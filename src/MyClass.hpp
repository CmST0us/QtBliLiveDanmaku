#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QWebSocket>
#include <QObject>
#include <libBliLiveDanmaku/DanmakuPacket.hpp>
#include <libBliLiveDanmaku/DanmakuPacketDecoder.hpp>

class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);
    void main();
signals:

public slots:
    void onViewDidLoad();
private:
    QWebSocket _socket;
    std::unique_ptr<blilive::DanmakuPacketDecoder> _decoder;
};

#endif // MYCLASS_HPP
