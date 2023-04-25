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

    // set level
    void setLevel(QString level);

    int score;
    int bestScore;

    int setBestScore(int newScore);

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



    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;
    QGraphicsTextItem *scoretTextItemInGame;

    int pillarDistance;

    QMediaPlayer *pointSoundPlayer;
    QAudioOutput *pointAudioOutput;
    QMediaPlayer *hitSoundPlayer;
    QAudioOutput *hitAudioOutput;

    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
