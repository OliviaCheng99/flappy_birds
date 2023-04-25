
#pragma once

#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H


#include <QWidget>

class User;

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AccountWindow(QWidget *parent = nullptr);
    ~AccountWindow();
    void setUser(const User &user);


signals:
    void showGameBoard();

private slots:
    void on_backButton_clicked();

private:
    Ui::AccountWindow *ui;
};

#endif // ACCOUNTWINDOW_H
