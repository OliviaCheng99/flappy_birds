#pragma once

#ifndef SIGNUP_H
#define SIGNUP_H

#include <QWidget>
#include<QFileDialog>
#include<QMessageBox>
#include"user.h"
#include<QJsonDocument>
#include<QJsonArray>
#include"gameboard.h"
#include <QThread>

class AppSettings;
class LoginWindow;


namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();


signals:
    void showGameBoard();
    void showLoginWindow();

private slots:
    void on_picButton_clicked(); // upload profile pricture
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::SignUp *ui;
    QString profilePicturePath;
    bool isUsernameValid(const QString &username);
    bool isPwdValid(const QString &pwd);
    bool isImgSizeValid(const QString &imgPath);
    void saveUser(const User &user);



};

#endif // SIGNUP_H
