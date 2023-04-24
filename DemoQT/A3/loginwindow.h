#pragma once

#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>

class SignUp;
class GameBoard;

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

private:
    Ui::LoginWindow *ui;
    GameBoard *gameBoard;
    SignUp* signupWin;


};
#endif // LOGINWINDOW_H
