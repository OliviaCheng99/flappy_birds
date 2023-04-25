#include "loginwindow.h"
#include "gameboard.h"
#include "signup.h"
#include "accountwindow.h"
#include <QPushButton>
#include "ui_loginwindow.h"
#include "appsettings.h"



LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    //gameBoard = new GameBoard();
    //gameBoard->setUser(user);
    //signupWin = new SignUp();
    //accountWindow = new AccountWindow();
    user = User();

    //connect( gameBoard, &GameBoard::showLoginWindow, this, &LoginWindow::onShowLoginWindow);
    //connect(ui->signupButton, &QCommandLinkButton::clicked,this, &LoginWindow::on_signupButton_clicked);
    //connect(signupWin, &SignUp::showLoginWindow,this, &LoginWindow::onShowLoginWindow);
    //connect(signupWin, &SignUp::showGameBoard, gameBoard, &GameBoard::onShowGameBoard);
    //connect(gameBoard, &GameBoard::showMyAccount, this, &LoginWindow::onShowMyAccount);

}

LoginWindow::~LoginWindow()
{
    delete ui;

}

void LoginWindow::on_loginButton_clicked()
{
    //   Validate the user's credentials
    // Get the username and password from input fields
    QString enteredUsername = ui->usernamelineEdit->text();
    QString enteredPassword = ui->pwdlineEdit->text();

    // Read the users.json file
    QString userFilePath = AppSettings::dirPath +"/database/users.json";
    qDebug() << userFilePath;
    QFile userFile(userFilePath);
    if (!userFile.open(QIODevice::ReadOnly))
    {
        // Handle the error
        QMessageBox::warning(this, "Error", "Something wrong,hahaha.");
        return;
    }

    QByteArray userFileData = userFile.readAll();
    userFile.close();

    QJsonDocument jsonDoc = QJsonDocument::fromJson(userFileData);
    QJsonArray jsonArray = jsonDoc.array();

    // Check if the entered username and password match any user in the file
    bool isValid = false;
    for (const QJsonValue &userValue : jsonArray)
    {
        QJsonObject userObject = userValue.toObject();
        if (userObject["username"].toString() == enteredUsername &&
            userObject["password"].toString() == enteredPassword)
        {
            isValid = true;
            user= User::fromJsonObject(userObject);
            break;
        }
    }

    if (isValid)
    {
        // If valid, go to the game board
        this->hide();
        GameBoard * gameBoard = new GameBoard;

        // on logout button clicked on game board window
        connect(gameBoard, &GameBoard::showLoginWindow, [=](){
            this->show();
        });

        gameBoard->show();


        // render user info to account window
        //AccountWindow account
        //this->accountWindow->setUser(user);

    }
    else
    {
        // If not valid, show an error message
        QMessageBox::warning(this, "Error", "Invalid username or password");
    }


}



void LoginWindow::on_signupButton_clicked()
{
    this->hide();
    SignUp* signupWin = new SignUp;

    connect(signupWin, &SignUp::showLoginWindow,[=](){
        this->show();
    });

    signupWin->show();
}

void LoginWindow::onShowMyAccount()
{
   // gameBoard->hide();
   // accountWindow->show();
}

