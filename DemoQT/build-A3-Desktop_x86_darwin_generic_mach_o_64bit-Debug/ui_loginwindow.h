/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *usernamelineEdit;
    QLineEdit *pwdlineEdit;
    QPushButton *loginButton;
    QCommandLinkButton *signupButton;
    QPushButton *pushButton;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName("LoginWindow");
        LoginWindow->resize(800, 600);
        label = new QLabel(LoginWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 160, 81, 20));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(110, 250, 58, 16));
        usernamelineEdit = new QLineEdit(LoginWindow);
        usernamelineEdit->setObjectName("usernamelineEdit");
        usernamelineEdit->setGeometry(QRect(200, 160, 301, 21));
        pwdlineEdit = new QLineEdit(LoginWindow);
        pwdlineEdit->setObjectName("pwdlineEdit");
        pwdlineEdit->setGeometry(QRect(200, 250, 301, 21));
        loginButton = new QPushButton(LoginWindow);
        loginButton->setObjectName("loginButton");
        loginButton->setGeometry(QRect(400, 320, 100, 32));
        signupButton = new QCommandLinkButton(LoginWindow);
        signupButton->setObjectName("signupButton");
        signupButton->setGeometry(QRect(270, 390, 131, 31));
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(200, 320, 100, 32));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "LoginWindow", nullptr));
        label->setText(QCoreApplication::translate("LoginWindow", "username", nullptr));
        label_2->setText(QCoreApplication::translate("LoginWindow", "password", nullptr));
        loginButton->setText(QCoreApplication::translate("LoginWindow", "submit", nullptr));
        signupButton->setText(QCoreApplication::translate("LoginWindow", "create an account", nullptr));
        pushButton->setText(QCoreApplication::translate("LoginWindow", "guest mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
