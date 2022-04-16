#include "game.h"
#include <QTimer>
#include <player.h>
#include <weapon.h>
#include <enemy.h>
#include <block.h>
#include <arrow.h>
//#include <arrow.h>
Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>),
    enemies(new QList<Enemy*>),
    arrows(new QList<Arrow*>)
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
    if(player->getWeapon()->getAttacking()) player->getWeapon()->animation();
    if(player->getInmu()) player->framesInmu();
    player->move();
    player->check();
    Enemy::update();
    Arrow::update();
    Block::update();
}
