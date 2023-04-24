#include "gameboard.h"
#include "ui_gameboard.h"

GameBoard::GameBoard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameBoard)
{
    ui->setupUi(this);

    connect(ui->logoutButton, &QPushButton::clicked, this, &GameBoard::on_logoutButton_clicked);


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

