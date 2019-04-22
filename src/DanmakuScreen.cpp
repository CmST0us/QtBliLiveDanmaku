#include <cstring>
#include <QTimer>
#include "DanmakuScreen.hpp"

DanmakuScreen::DanmakuScreen(QObject *parent) : QObject(parent),
    _decoder{std::unique_ptr<blilive::DanmakuPacketDecoder>(new blilive::DanmakuPacketDecoder)} {

}

void DanmakuScreen::onViewDidLoad() {
    _decoder.get()->mCommandMessageHandler = [&](blilive::DanmakuCommandPacket *p, std::string c) {
        if (c == blilive::DanmakuCommandPacket::Command::RecvDanmaku) {
            auto danmu = static_cast<blilive::DanmakuCommandDanmuMessagePacket *>(p);
            QString text = QString::fromStdString(danmu->text()).toUtf8();
            QString author = QString::fromStdString(danmu->authorNick()).toUtf8();
            qDebug()<<author<<": "<<text<<"\r\n";
        }
    };

    QObject::connect(&_socket, &QWebSocket::connected, this, [&]() {
       printf("Connected\n");
       blilive::DanmakuAuthPacket auth;
       auth.mRoomID = 1440094;
       std::string data = auth.encode();
       this->_socket.sendBinaryMessage(QByteArray(data.c_str(), static_cast<int>(data.size())));
    });

    QObject::connect(&_socket, &QWebSocket::binaryMessageReceived, this, [&](const QByteArray &message) {
       this->_decoder.get()->dispatch(std::string(message.data(), static_cast<size_t>(message.size())));
    });

    _socket.open(QUrl(QString("wss://broadcastlv.chat.bilibili.com:2245/sub")));
}
