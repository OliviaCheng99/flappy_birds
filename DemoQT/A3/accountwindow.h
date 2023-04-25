
#pragma once

#ifndef ACCOUNTWINDOW_H
#define ACCOUNTWINDOW_H


#include <QWidget>

class AppSettings;
class LoginWindow;
class User;

namespace Ui {
class AccountWindow;
}

class AccountWindow : public QWidget
{
    Q_OBJECT

signals:
    void backButtonClicked();

public:
    explicit AccountWindow(QWidget *parent = nullptr);
    ~AccountWindow();
    void setUser(const User &user);

private slots:
    void on_backButton_clicked();

private:
    Ui::AccountWindow *ui;
};

#endif // ACCOUNTWINDOW_H
