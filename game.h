#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <motion.h>
#include <QVector>
class QTimer;
class Block;
class Player;
class Game : public QGraphicsView
{

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    Player *player;
    QTimer *timer;
    QVector<Block*> *blocks;
};

#endif // GAME_H
