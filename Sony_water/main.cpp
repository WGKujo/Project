#include "widget.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QString qss;
    QFile qssFile("E:/Qt/Sony_water/res/Myqss.qss");
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        //qDebug()<<"1";
        //qss=QLatin1String(qssFile.readAll());
        qss=QString::fromUtf8(qssFile.readAll());
        qApp->setStyleSheet(qss);
        qssFile.close();
    }

    return a.exec();
}
