#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::clicked, this, &GameBoard::on_logoutButton_clicked);
    connect(&gameWidget, &Widget::showGameBoard, this, &GameBoard::onShowGameBoard);
}

GameBoard::~GameBoard()
{
    delete ui;
}


void GameBoard::on_logoutButton_clicked()
{
    this->hide();
    emit showLoginWindow();
}

void GameBoard::onShowGameBoard(){
    this->show();
}

void GameBoard::on_checkAccountButton_clicked()
{
    this->hide();
    emit showMyAccount();
}


void GameBoard::on_startGame_clicked()
{
    this->hide();
    gameWidget.show();
}
