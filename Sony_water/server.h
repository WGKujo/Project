#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>
#include<QJsonObject>
#include <QJsonDocument>

class server : public QTcpServer
{
  Q_OBJECT
public:
    server();
    void onNewClientConnected();
    //void readmessage();
    bool ret;
     QJsonObject jsonObject;
signals:
    void new_connect(QString,quint16);
    //void readmessage(int);
    void readmessage(QString);

    void updateline1(QString);

    void updateline2(QString);

    void updateline3(QString);

    void updateline4(QString);

    void switchmode();

    void switch4G();

private:
    QTcpSocket* cs;
    QTcpServer *s;
public slots:
    void testTDS();
    void testTEM();
    void testTU();
    void testPH();
    void start();

};

#endif // SERVER_H
