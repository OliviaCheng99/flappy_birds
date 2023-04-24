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

    void addBird();
    void startGame();
    void initSoundEffect();

    bool getGameOn() const;
    void setGameOn(bool newGameOn);
    void incrementScore();

signals:

public slots:

private:
    void showGameOverGraphics();
    void hideGameOverGraphics();
    void cleanPillars();
    void setUpPillarTimer();
    void freezeBirdAndPillarsInPlace();

    QTimer *pillarTimer;
    BirdItem *bird;


    bool gameOn;

    int score;
    int bestScore;

    QGraphicsPixmapItem *gameOverPix;
    QGraphicsTextItem *scoreTextItem;


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
