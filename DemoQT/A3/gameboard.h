#pragma once

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "widget.h"
#include "user.h"
#include "accountwindow.h"

class LoginWindow;

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
//    void setUser(const User &user);
    ~GameBoard();
    void setUser(User user);


signals:
    void showLoginWindow();
    void showMyAccount();


public slots:
    void onShowGameBoard();
//    void init();

private slots:
    //void onAccountButtonClicked();
    void on_logoutButton_clicked();
    void on_checkAccountButton_clicked();
    void on_startGame_clicked();

private:
    Ui::GameBoard *ui;
    LoginWindow *loginWindow;
    User my_user;
    int bestScore;
    int lastScore;
};

#endif // GAMEBOARD_H
