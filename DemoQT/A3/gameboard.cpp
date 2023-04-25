#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
//    bestScore = alice->getBestScore();
    bestScore = 7;

    ui->setupUi(this);
}

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
    this->close();
    emit showMyAccount();
}


void GameBoard::on_startGame_clicked()
{
    Widget *newGameWidget = new Widget();
    newGameWidget->setBestScore(bestScore);

    connect(newGameWidget, &Widget::showGameBoard, [=](){

        lastScore = newGameWidget->getLastScore();

        if(newGameWidget->getBestScore() > bestScore)
            bestScore = newGameWidget->getBestScore();
//        alice->updateScore(bestScore);
        qDebug() << "last score: " << lastScore << " " << "best score: " << bestScore << "\n" ;

        this->show();
    });

    newGameWidget->show();
    this->hide();
}

void GameBoard:: setUser(User user){
    my_user = user;
}
