 #include "server.h"
#include "form.h"
#include "ui_form.h"

server::server()
{
  s=new QTcpServer;
  ret=s->listen(QHostAddress::AnyIPv4,8848);
//  ret=s->listen(QHostAddress::AnyIPv4,8848);
  if(!ret)
    {
      qDebug()<<"监听失败";
    }
  qDebug()<<"开启监听";
  connect(s,&QTcpServer::newConnection,this,&server::onNewClientConnected);
  //connect(f,&Form::testTDS,this,&server::testTDS);
}

void server::onNewClientConnected()
{
  cs = s->nextPendingConnection();
  emit new_connect(cs->peerAddress().toString(),cs->peerPort());
  connect(cs,&QTcpSocket::readyRead,this,[=]()
  {
      QByteArray data = cs->readAll();
      //int msg = data.toInt();
      QString msg =QString::fromUtf8(data);
      QString x="!";
      QString x1="a";
      QString x2="b";
      QString x3="c";
      QString x4="d";
      qDebug()<<msg;
//      qDebug()<<data;
//      cs->write(data);
//      qDebug()<<msg.indexOf(x);
      if(msg=="x")
        {
          emit switchmode();
        }
      if(msg=="G")
        {
          emit switch4G();
        }
      if(msg.indexOf(x)>0)
        {
          emit readmessage(msg);
          qDebug()<<"测试"<<msg;
        }
      if(msg.indexOf(x1)>0)
        {
          QString msgtds=msg.mid(0,msg.indexOf(x1));
          //QString msgtds=msg.mid(msg.indexOf(x1),7);
          qDebug()<<"消息1"<<msgtds;
          //QString msgtds1=msgtds.right(6);
          //qDebug()<<"截取"<<msgtds1;
          emit updateline1(msgtds);
        }
      if(msg.indexOf(x2)>0)
        {
          QString msgph=msg.mid(msg.indexOf(x1)+1,msg.indexOf(x2)-msg.indexOf(x1)-1);
          qDebug()<<"消息2"<<msgph;
          qDebug()<<msg.indexOf(x2);
          //QString msgph1=msgph.right(6);
          //qDebug()<<"截取"<<msgph1;
          emit updateline2(msgph);
        }
      if(msg.indexOf(x3)>0)
        {
          QString msgtem=msg.mid(msg.indexOf(x2)+1,msg.indexOf(x3)-msg.indexOf(x2)-1);
          qDebug()<<"消息3"<<msgtem;
          //QString msgtem1=msgtem.right(6);
          //qDebug()<<"截取"<<msgtem1;
          emit updateline3(msgtem);
        }
      if(msg.indexOf(x4)>0)
        {
          QString msgtu=msg.mid(msg.indexOf(x3)+1,msg.indexOf(x4)-msg.indexOf(x3)-1);
          qDebug()<<"消息4"<<msgtu;
          //QString msgtu1=msgtu.right(6);
          //qDebug()<<"截取"<<msgtu1;
          emit updateline4(msgtu);
        }
    });
}

void server::testTDS()
{
  qDebug()<<"TDS";
  cs->write("1");
  //   jsonObject.insert("TDS", "test1");
  //   QJsonDocument jsonDocument;
  //   jsonDocument.setObject(jsonObject);
  //   QByteArray dataArray = jsonDocument.toJson();
  //  cs->write(dataArray);
}

void server::testPH()
{
  qDebug()<<"PH";
  cs->write("2");
}

void server::testTEM()
{
  qDebug()<<"TEM";
  cs->write("3");
}

void server::testTU()
{
  qDebug()<<"TU";
  cs->write("4");
}

void server::start()
{
  qDebug()<<"折线图";
  cs->write("S");//进入正常工作状态
}


