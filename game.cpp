#include "game.h"
#include <QTimer>
#include <player.h>
Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>),
    enemies(new QList<Enemy*>)
{
    setParent(parent);
    setGeometry(0,0,1280,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(new QGraphicsScene);
    scene()->setSceneRect(0,0,width(),height());
    connect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    timer->start(CLOCK_GAME);
}

Game::~Game()
{
    delete player;
    delete timer;
    blocks->clear();
    delete blocks;
    enemies->clear();
    delete enemies;
    scene()->clear();
    delete scene();
}

void Game::timeWorld()
{
    player->move();
}
