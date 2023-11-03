#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    QString filename("E:/Qt/Sony_water/res/3.png");
    QImage* img=new QImage;
    if(! ( img->load(filename) ) ) //加载图像
    {
        qDebug()<<"打开图片错误";
        delete img;
        return;
    }
    ui->icon1->setPixmap(QPixmap::fromImage(*img));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_loginexit_btn_clicked()
{
    this->close();
}

void Widget::on_login_btn_clicked()
{
    this->hide();
    form.show();
}
