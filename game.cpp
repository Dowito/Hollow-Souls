#include "game.h"
#include <QTimer>
#include <player.h>
#include <weapon.h>
#include <enemy.h>
#include <block.h>
#include <arrow.h>
#include <dash.h>
#include <bow.h>
#include <healthbar.h>
#include <QGraphicsRectItem>
#include "Screens/world.h"
//motion
qreal Motion::periodo;
//Dash
Player *Dash::player;
//arrow
Player *Arrow::player;
QVector<Block*> *Arrow::blocks;
QList<Enemy*> *Arrow::enemies;
QList<Arrow*> *Arrow::arrows;

Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>),
    enemies(new QList<Enemy*>),
    arrows(new QList<Arrow*>),
    world(new World(this))
{
    initStaticVar();
    setParent(parent);
    setGeometry(0,0,1280,720);
    setFixedSize(1280,720);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //iniciando player
    player = new Player;
    player->setBlocks(blocks);
    player->setHealthBar(new HealthBar(player));
    player->setWeapon(new Weapon(player));
    player->setDash(new Dash);
    player->setBow(new Bow);
    Dash::setPlayer(player);
    Arrow::setPlayer(player);
    //cargando mundo
    world->loadWorld(0);
    setScene(world);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    timer->start(CLOCK_GAME);
}

void Game::timeWorld()
{
    //if(player->getWeapon()->getAttacking()) player->getWeapon()->animation();
    //if(player->getInmu()) player->framesInmu();
    //player->move();
    player->check();
    //Enemy::update();
    Arrow::update();
    //Block::update();
}

void Game::initStaticVar()
{
    //Motion
    Motion::setPeriodo(TTT);
    //Arrow
    Arrow::setEnemies(enemies);
    Arrow::setBlocks(blocks);
    Arrow::setArrows(arrows);
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
