#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
    //    bestScore = alice->getBestScore();

    //    ui->ranking->setNum();
    ui->setupUi(this);
}

//void GameBoard::setUser(const User &user) {
//    ui->ranking->setNum(user.getRanking());
//    ui->lastScore->setNum(user.getLastScore());
//}

GameBoard::~GameBoard()
{
    delete ui;
}

void GameBoard::on_logoutButton_clicked()
{
    this->close();
    emit showLoginWindow();
}

void GameBoard::onShowGameBoard(){
    //qDebug() << "here";
    //this->contentsRect();
    this->show();
}

void GameBoard::on_checkAccountButton_clicked()
{
    this->hide();
    AccountWindow *accountWindow = new AccountWindow();
    accountWindow->setUser(my_user);

    connect(accountWindow, &AccountWindow::backButtonClicked, [=]{
        this->show();
    });
    accountWindow->show();
}


void GameBoard::on_startGame_clicked()
{
    bestScore = my_user.getBestScore();
    Widget *newGameWidget = new Widget();
    newGameWidget->setBestScore(bestScore);

    connect(newGameWidget, &Widget::showGameBoard, [=](){

        lastScore = newGameWidget->getLastScore();

        if(newGameWidget->getBestScore() > bestScore)
            bestScore = newGameWidget->getBestScore();
        my_user.updateScore(bestScore);
        qDebug() << "last score: " << lastScore << " " << "best score: " << bestScore << "\n" ;

        this->show();
    });

    newGameWidget->show();
    this->hide();
}

void GameBoard:: setUser(User user){
    my_user = user;
    ui->ranking->setNum(user.getRanking());
    ui->bestScore->setNum(user.getBestScore());
}
