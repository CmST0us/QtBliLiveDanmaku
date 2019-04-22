#ifndef DANMAKUSCREEN_HPP
#define DANMAKUSCREEN_HPP

#include <QWebSocket>
#include <QObject>
#include <QTimer>
#include <libBliLiveDanmaku/DanmakuPacket.hpp>
#include <libBliLiveDanmaku/DanmakuPacketDecoder.hpp>

class DanmakuScreen : public QObject
{
    Q_OBJECT
public:
    explicit DanmakuScreen(QObject *parent = nullptr);
signals:

public slots:
    void connectLiveRoom(int roomID);
    void sendHeartbeat();

private:
    std::unique_ptr<QWebSocket> _socket;
    std::unique_ptr<blilive::DanmakuPacketDecoder> _decoder;
    QTimer _heartbeatTimer;

    void startHeartbeat();
    void stopHeartbeat();

};

#endif // DANMAKUSCREEN_HPP
