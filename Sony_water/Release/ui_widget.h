/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QFrame *loginframe;
    QLabel *logintitle;
    QPushButton *loginexit_btn;
    QPushButton *login_btn;
    QLabel *img1;
    QLabel *img2;
    QLineEdit *Account;
    QLineEdit *Password;
    QLabel *icon1;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(500, 700);
        loginframe = new QFrame(Widget);
        loginframe->setObjectName(QString::fromUtf8("loginframe"));
        loginframe->setGeometry(QRect(0, 0, 500, 700));
        loginframe->setFrameShape(QFrame::StyledPanel);
        loginframe->setFrameShadow(QFrame::Raised);
        logintitle = new QLabel(loginframe);
        logintitle->setObjectName(QString::fromUtf8("logintitle"));
        logintitle->setGeometry(QRect(90, 240, 341, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(25);
        font.setBold(false);
        font.setWeight(50);
        logintitle->setFont(font);
        loginexit_btn = new QPushButton(loginframe);
        loginexit_btn->setObjectName(QString::fromUtf8("loginexit_btn"));
        loginexit_btn->setGeometry(QRect(450, 0, 51, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(20);
        loginexit_btn->setFont(font1);
        login_btn = new QPushButton(loginframe);
        login_btn->setObjectName(QString::fromUtf8("login_btn"));
        login_btn->setGeometry(QRect(50, 570, 401, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(19);
        login_btn->setFont(font2);
        img1 = new QLabel(loginframe);
        img1->setObjectName(QString::fromUtf8("img1"));
        img1->setGeometry(QRect(50, 370, 40, 40));
        img2 = new QLabel(loginframe);
        img2->setObjectName(QString::fromUtf8("img2"));
        img2->setGeometry(QRect(50, 450, 40, 40));
        Account = new QLineEdit(loginframe);
        Account->setObjectName(QString::fromUtf8("Account"));
        Account->setGeometry(QRect(110, 370, 341, 51));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font3.setPointSize(16);
        Account->setFont(font3);
        Password = new QLineEdit(loginframe);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(110, 450, 341, 51));
        Password->setFont(font3);
        Password->setEchoMode(QLineEdit::Password);
        icon1 = new QLabel(loginframe);
        icon1->setObjectName(QString::fromUtf8("icon1"));
        icon1->setGeometry(QRect(170, 40, 150, 150));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        logintitle->setText(QApplication::translate("Widget", "\346\260\264\350\264\250\346\243\200\346\265\213\346\212\245\350\255\246\347\263\273\347\273\237", nullptr));
        loginexit_btn->setText(QApplication::translate("Widget", "\303\227", nullptr));
        login_btn->setText(QApplication::translate("Widget", "\347\231\273\345\275\225", nullptr));
        img1->setText(QString());
        img2->setText(QString());
        Account->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\350\264\246\345\217\267", nullptr));
        Password->setPlaceholderText(QApplication::translate("Widget", "\350\257\267\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        icon1->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
