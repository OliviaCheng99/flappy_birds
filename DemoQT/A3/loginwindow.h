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

signals:

private slots:
    void on_loginButton_clicked();
    void onShowLoginWindow();
    void on_signupButton_clicked();
    void onShowMyAccount();

private:
    Ui::LoginWindow *ui;
    GameBoard *gameBoard;
    SignUp* signupWin;
    AccountWindow *accountWindow;
    User user;
};
#endif // LOGINWINDOW_H
