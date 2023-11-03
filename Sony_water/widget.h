#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form.h"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_loginexit_btn_clicked();

    void on_login_btn_clicked();

private:
    Ui::Widget *ui;
    Form form;


};

#endif // WIDGET_H
