#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <motion.h>
#include <QVector>
class QTimer;
class Block;
class Game : public QGraphicsView
{

public:
    explicit Game(QWidget *parent = nullptr);
    Motion *prueba;
    QTimer *timer;
    QVector<Block*> *blocks;
};

#endif // GAME_H
