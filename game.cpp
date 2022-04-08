#include "game.h"
#include <motion.h>
#include <QTimer>
#include <player.h>
Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>)
{
    setParent(parent);
    setGeometry(0,0,1280,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(new QGraphicsScene);
    scene()->setSceneRect(0,0,width(),height());
    timer->start(CLOCK_GAME);
}

Game::~Game()
{
    delete player;
    delete timer;
    blocks->clear();
    delete blocks;
    scene()->clear();
    delete scene();
}
