#pragma once

#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <QWidget>

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
    void setGreeting();


signals:
    void showLoginWindow();
    void showMyAccount();
    void logoutsignal();

public slots:
    void onShowGameBoard();

private slots:
    //void onAccountButtonClicked();

    void on_logoutButton_clicked();

    void on_checkAccountButton_clicked();

private:
    Ui::GameBoard *ui;
    LoginWindow *loginWindow;
};

#endif // GAMEBOARD_H
