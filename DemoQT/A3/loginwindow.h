#pragma once

#include "widget.h"
#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "user.h"

class SignUp;
class GameBoard;
class AccountWindow;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginWindow; }
QT_END_NAMESPACE

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();
    User user;

signals:

private slots:
    void on_loginButton_clicked();
    void on_signupButton_clicked();
    void onShowMyAccount();
    void on_pushButton_clicked();

private:
    Ui::LoginWindow *ui;

};
#endif // LOGINWINDOW_H
