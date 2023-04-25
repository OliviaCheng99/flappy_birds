#pragma once

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>
#include "widget.h"

class LoginWindow;

namespace Ui {
class GameBoard;
}

class GameBoard : public QWidget
{
    Q_OBJECT

public:
    explicit GameBoard(QWidget *parent = nullptr);
    ~GameBoard();


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
};

#endif // GAMEBOARD_H
