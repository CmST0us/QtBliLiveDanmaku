#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <QWebSocket>
#include <QObject>

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
};

#endif // MYCLASS_HPP
