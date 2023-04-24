#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>


Scene::Scene(QObject *parent) : QGraphicsScene(parent),
    gameOn(false), score(0), bestScore(0)

{
    setUpPillarTimer();


}

// when game start
void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer, &QTimer::timeout,[=](){
        PillarItem * pillarItem = new PillarItem();
        connect(pillarItem, &PillarItem::collideFail,[=](){
            pillarTimer->stop();
            freezeBirdAndPillarsInPlace();
            setGameOn(false);
            showGameOverGraphics();

        });

        addItem(pillarItem);
    });

    //    pillarTimer->start(1000);



}


// when game stop
void Scene::freezeBirdAndPillarsInPlace()
{
    // freeze bird
    bird->freezeInPlace();

    // freeze pillars
    QList<QGraphicsItem *> sceneItems = items();
    foreach(QGraphicsItem *item, sceneItems){
        PillarItem *pillar = dynamic_cast<PillarItem *>(item);
        if(pillar){
            pillar->freezeInPlace();
        }
    }

}

bool Scene::getGameOn() const
{
    return gameOn;
}

void Scene::setGameOn(bool newGameOn)
{
    gameOn = newGameOn;
}

void Scene::incrementScore()
{
    score++;
    if(score > bestScore)
        bestScore = score;
    qDebug() << "Score: " << score << " Best Score: " << bestScore;
    scoretTextItemInGame->setPlainText(QString("Score: ") + QString::number(score) + QString("\nBest Score : " + QString::number(bestScore)));

}

void Scene::showGameOverGraphics()
{
    gameOverPix = new QGraphicsPixmapItem(QPixmap("://images/game_over.png").scaled(424,300));
    addItem(gameOverPix);
    gameOverPix->setPos(QPointF(0,0) - QPointF(gameOverPix->boundingRect().width()/2,
                                                gameOverPix->boundingRect().height()/2));

    scoreTextItem = new QGraphicsTextItem();

    QString htmlString = "<p> Score : " + QString::number(score) + " </p>"
                         + "<p> Best Score : " + QString::number(bestScore) + "</p>";
    QFont mFont("Consolas", 30, QFont::Bold);

    scoreTextItem->setHtml(htmlString);
    scoreTextItem->setFont(mFont);
    scoreTextItem->setDefaultTextColor(Qt::yellow);
    addItem(scoreTextItem);

    scoreTextItem->setPos(QPointF(0,0) - QPointF(scoreTextItem->boundingRect().width()/2,
                                                -gameOverPix->boundingRect().height()/2));

    if(scoretTextItemInGame){
        scoretTextItemInGame->setPlainText(QString(""));
    }

}

void Scene::hideGameOverGraphics()
{
    if(gameOverPix){
        removeItem(gameOverPix);
        delete gameOverPix;
        gameOverPix = nullptr;
    }
    if(scoreTextItem){
        removeItem(scoreTextItem);
        delete scoreTextItem;
        scoreTextItem = nullptr;
    }
    if(scoretTextItemInGame){
        scoretTextItemInGame->setPlainText(QString("Score: ") + QString::number(score) + QString("\nBest Score : " + QString::number(bestScore)));
    }
}

void Scene::cleanPillars()
{
    QList<QGraphicsItem *> sceneItems = items();
    foreach(QGraphicsItem *item, sceneItems){
        PillarItem *pillar = dynamic_cast<PillarItem *>(item);
        if(pillar){
            removeItem(pillar);
            delete pillar;
        }
    }
}

void Scene::addBird()
{
    bird = new BirdItem(QPixmap("://images/bird_down.png").scaled(40,30));
    addItem(bird);

}

void Scene::addScore()
{
    scoretTextItemInGame = new QGraphicsTextItem();
    scoretTextItemInGame->setPlainText(QString("Score: ") + QString::number(score) + QString("\nBest Score : " + QString::number(bestScore)));
    scoretTextItemInGame->setDefaultTextColor(Qt::yellow);
    scoretTextItemInGame->setFont(QFont("times", 16));
    scoretTextItemInGame->setPos(-200,-250);
    addItem(scoretTextItemInGame);
}

void Scene::startGame()
{
    // start bird animation
    bird->startFlying();
    // start pillars animation
    if(!pillarTimer->isActive()){
        cleanPillars();
        score = 0;
        setGameOn(true);
        hideGameOverGraphics();
        pillarTimer->start(1000);
    }

}


// shoot up event
void Scene::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Space)
        if(gameOn)
            bird->shootUp();
    QGraphicsScene::keyPressEvent(event);
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        if(gameOn)
            bird->shootUp();
    }

    QGraphicsScene::mousePressEvent(event);
}
