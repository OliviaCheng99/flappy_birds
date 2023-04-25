#include "accountwindow.h"
#include "ui_accountwindow.h"
#include "user.h"

AccountWindow::AccountWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountWindow)
{
    ui->setupUi(this);
}

AccountWindow::~AccountWindow()
{
    delete ui;
}

void AccountWindow::setUser(const User &user)
{
    ui->usernameVal->setText(user.getUsername());
    ui->firstnameVal->setText(user.getFirstName());
    ui->lastnameVal->setText(user.getLastName());
    ui->bdayVal->setText(user.getBirthDate().toString("yyyy-MM-dd"));
    QString profilePicturePath = user.getProfilePicturePath();
    QPixmap profilePicture(profilePicturePath);
    ui->picVal->setPixmap(profilePicture.scaled(ui->picVal->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));// set pic size with label size

}


void AccountWindow::on_backButton_clicked()
{
    emit showGameBoard();
    this->close();
}

