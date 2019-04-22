#ifndef DANMAKUSCREEN_HPP
#define DANMAKUSCREEN_HPP

#include <QWebSocket>
#include <QObject>
#include <libBliLiveDanmaku/DanmakuPacket.hpp>
#include <libBliLiveDanmaku/DanmakuPacketDecoder.hpp>

class DanmakuScreen : public QObject
{
    Q_OBJECT
public:
    explicit DanmakuScreen(QObject *parent = nullptr);
    void main();
signals:

public slots:
    void onViewDidLoad();
private:
    QWebSocket _socket;
    std::unique_ptr<blilive::DanmakuPacketDecoder> _decoder;
};

#endif // DANMAKUSCREEN_HPP
