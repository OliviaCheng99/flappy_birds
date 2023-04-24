#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QTimer>

#include "pillaritem.h"
#include "birditem.h"

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = nullptr);


    // add bird in widget.cpp
    void addBird();

    // game start
    void startGame();
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


    // QGraphicsScene interface
protected:
    void keyPressEvent(QKeyEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // SCENE_H
