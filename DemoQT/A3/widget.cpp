#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsPixmapItem>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // set scene
    // window size: 400x500
    scene = new Scene(this);
    scene->setSceneRect(-200,-250,400,500);

    // set background
    QGraphicsPixmapItem * backgroundItem = new QGraphicsPixmapItem(QPixmap("://images/background.png"));

    scene->addItem(backgroundItem);
    backgroundItem->setPos(QPointF(0,0) - QPointF(backgroundItem->boundingRect().width()/2, backgroundItem->boundingRect().height()/2));

    // add bird
    scene->addBird();



    ui->graphicsView->setScene(scene);
}

void Widget::init(){
    ui->setupUi(this);

    // set scene
    // window size: 400x500
    scene = new Scene(this);
    scene->setSceneRect(-200,-250,400,500);

    // set background
    QGraphicsPixmapItem * backgroundItem = new QGraphicsPixmapItem(QPixmap("://images/background.png"));

    scene->addItem(backgroundItem);
    backgroundItem->setPos(QPointF(0,0) - QPointF(backgroundItem->boundingRect().width()/2, backgroundItem->boundingRect().height()/2));

    // set grid ( delete after finish)
    //    scene->addLine(-400,0,400,0,QPen(Qt::blue));
    //    scene->addLine(0,-400,0,400,QPen(Qt::blue));

    // add bird
    scene->addBird();

//    // add score
//    scene->addScore();

    ui->graphicsView->setScene(scene);

}

int Widget::getLastScore()
{
    return scene->score;
}

int Widget::getBestScore(){
    return scene->bestScore;
}

int Widget::setBestScore(int newScore)
{
    scene->setBestScore(newScore);
}


Widget::~Widget()
{
    delete ui;
}


void Widget::on_startGameButton_clicked()
{
    scene->startGame();
    // add score
    scene->addScore();
}


void Widget::on_easyButton_clicked()
{
    scene->setLevel("Easy");
}


void Widget::on_normalButton_clicked()
{
    scene->setLevel("Normal");
}


void Widget::on_hardButton_clicked()
{
    scene->setLevel("Hard");
}


void Widget::on_backButton_clicked()
{
    emit showGameBoard();
    this->close();
}


