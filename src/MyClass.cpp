#include <QtWebSockets>
#include "MyClass.hpp"
MyClass::MyClass(QObject *parent) : QObject(parent) {

}

void MyClass::onViewDidLoad() {
    QObject::connect(&_socket, &QWebSocket::connected, this, [&]() {
       printf("Connected\n");
    });
    QObject::connect(&_socket, &QWebSocket::binaryMessageReceived, this, [&](const QByteArray &message) {
       printf("read %d\n", message.size());
    });
    _socket.open(QUrl(QString("wss://broadcastlv.chat.bilibili.com:2245/sub")));
}
