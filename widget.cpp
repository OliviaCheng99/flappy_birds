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

    // set grid ( delete after finish)
//    scene->addLine(-400,0,400,0,QPen(Qt::blue));
//    scene->addLine(0,-400,0,400,QPen(Qt::blue));

    // add bird
    scene->addBird();

//    // add score
    scene->addScore();


    ui->graphicsView->setScene(scene);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_startGameButton_clicked()
{
    scene->startGame();
}

