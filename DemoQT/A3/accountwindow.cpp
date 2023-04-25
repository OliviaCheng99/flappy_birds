#include "accountwindow.h"
#include "appsettings.h"
#include "loginwindow.h"
#include "ui_accountwindow.h"
#include "user.h"

AccountWindow::AccountWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AccountWindow)
{
    ui->setupUi(this);

//    connect(ui->backButton, &QPushButton::clicked, this, &AccountWindow::on_backButton_clicked);
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

    QString imagePath = AppSettings::dirPath + "/database/" + profilePicturePath;

    QPixmap profilePicture(imagePath);

    ui->picVal->setPixmap(profilePicture.scaled(ui->picVal->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));// set pic size with label size
}

void AccountWindow::on_backButton_clicked()
{
    emit backButtonClicked();
    this->close();
}

