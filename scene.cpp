#include "scene.h"
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>
#include <chrono>
#include <thread>


Scene::Scene(QObject *parent) : QGraphicsScene(parent),
    gameOn(false), score(0), bestScore(0), pillarDistance(90)

{
    setUpPillarTimer();
    initSoundEffect();
}

void Scene::initSoundEffect(){
    pointSoundPlayer = new QMediaPlayer;
    pointAudioOutput = new QAudioOutput;
    hitSoundPlayer = new QMediaPlayer;
    hitAudioOutput = new QAudioOutput;

    // initialize sound effects
    pointSoundPlayer->setAudioOutput(pointAudioOutput);
    pointSoundPlayer->setSource(QUrl("qrc:/sounds/point.mp3"));
    pointSoundPlayer->setPlaybackRate(2);
    pointAudioOutput->setVolume(100);

    hitSoundPlayer->setAudioOutput(hitAudioOutput);
    hitSoundPlayer->setSource(QUrl("qrc:/sounds/hit.mp3"));
    hitSoundPlayer->setPlaybackRate(0.5);
    hitAudioOutput->setVolume(80);
}

// when game start
void Scene::setUpPillarTimer()
{
    pillarTimer = new QTimer(this);
    connect(pillarTimer, &QTimer::timeout,[=](){
        PillarItem * pillarItem = new PillarItem(pillarDistance);
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

    if(pillarDistance == 120)
        score++;
    else if(pillarDistance == 90)
        score += 2;
    else
        score += 3;


    pointSoundPlayer->play();
    if(score > bestScore)
        bestScore = score;
    qDebug() << "Score: " << score << " Best Score: " << bestScore;
    scoretTextItemInGame->setPlainText(QString("Score: ") + QString::number(score) + QString("\nBest Score : " + QString::number(bestScore)));

}

void Scene::setLevel(QString level)
{
    if(level == "Easy")
        pillarDistance = 120;
    else if (level == "Normal")
        pillarDistance = 90;
    else if(level == "Hard")
        pillarDistance = 60;
    else
        pillarDistance = 90;
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
    
    hitSoundPlayer->play();// play hit sound effect
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
