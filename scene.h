#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>

#include "birditem.h"
#include "pillaritem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);
    QMediaPlayer *pointSoundPlayer;
    QAudioOutput *pointAudioOutput;
    QMediaPlayer *hitSoundPlayer;
    QAudioOutput *hitAudioOutput;

    // add bird in widget.cpp
    void addBird();
    void startGame();
    void initSoundEffect();

    // add score
    void addScore();

    // game start
    bool getGameOn() const;
    void setGameOn(bool newGameOn);

    // score
    void incrementScore();

signals:

public slots:

private:

    // when game over
    void showGameOverGraphics();
    void hideGameOverGraphics();
    void cleanPillars();
    void freezeBirdAndPillarsInPlace();

    // when game start
    void setUpPillarTimer();

    QTimer *pillarTimer;
    BirdItem *bird;


    bool gameOn;

    int score;
    int bestScore;

    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *scoretTextItemInGame;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
