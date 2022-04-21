#include "game.h"
#include <QTimer>
#include <player.h>
#include <weapon.h>
#include <enemy.h>
#include <block.h>
#include <motionblock.h>
#include <arrow.h>
#include <dash.h>
#include <bow.h>
#include <healthbar.h>
#include "Utilities/portal.h"
#include "Screens/loadscreen.h"
#include "Screens/gameover.h"
#include "Screens/menu.h"
#include <QGraphicsRectItem>
#include "Screens/world.h"
//motion
qreal Motion::periodo;
//Portal
Player *Portal::player;
QVector<Portal*> *Portal::portals;
//Dash
Player *Dash::player;
//Block
QVector<Block*> *Block::blocks;
//MotionBlock
QList<Enemy*> *MotionBlock::enemies;
Player *MotionBlock::player;
//arrow
Player *Arrow::player;
QVector<Block*> *Arrow::blocks;
QList<Enemy*> *Arrow::enemies;
QList<Arrow*> *Arrow::arrows;
//enemigo
Player* Enemy::player;
QVector<Block*>* Enemy::blocks;
QList<Enemy*>* Enemy::enemies;

Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>),
    portals(new QVector<Portal*>),
    enemies(new QList<Enemy*>),
    arrows(new QList<Arrow*>),
    world(new World(this))
{
    initStaticVar();
    setParent(parent);
    setGeometry(160,90,1280,720);
    setSceneRect(0,0,1280,720);
    //setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    //iniciando player
    player = new Player;
    player->setBlocks(blocks);
    player->setHealthBar(new HealthBar(player));
    player->setWeapon(new Weapon(player));
    player->setDash(new Dash);
    player->setBow(new Bow);
    world->initPlayer();
    Dash::setPlayer(player);
    Arrow::setPlayer(player);
    Enemy::setPlayer(player);
    MotionBlock::setPlayer(player);
    Portal::setPlayer(player);
    //cargando mundo
    world->loadWorld(0, {11*SB+100, 4*SB+100});
    //world->loadWorld(1, {14*SB,6*SB+100}); //(14,6) , (16,17)
    //world->loadWorld(2, {16*SB,17*SB+100});
    //world->loadWorld(3, {13*SB,7*SB});
    //world->loadWorld(4,{14*SB,4*SB+100}); //world->loadWorld(4,{14*SB,19*SB+100});
    //world->loadWorld(5,{21*SB,7*SB+100});
    setScene(world);
    connect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    timer->start(CLOCK_GAME);
}

void Game::timeWorld()
{
    player->check();
    Enemy::update();
    Arrow::update();
    Block::update();
    Portal::update();
}

void Game::loadNextWorld(Portal *portal)
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    player->clearFocus();
    setScene(nullptr);//poner pantalla de carga.
    world->loadWorld(portal->getNextWorld(), portal->getPosPlayerNextWorld());
    setScene(world);
    player->setFocus();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    timer->start(CLOCK_GAME);
}

void Game::initStaticVar()
{
    //Motion
    Motion::setPeriodo(TTT);
    //Portal
    Portal::setPortals(portals);
    //Block
    Block::setBlocks(blocks);
    //MotionBlock
    MotionBlock::setEnemies(enemies);
    //Arrow
    Arrow::setEnemies(enemies);
    Arrow::setBlocks(blocks);
    Arrow::setArrows(arrows);
    //Enemy
    Enemy::setBlocks(blocks);
    Enemy::setEnemies(enemies);
}

Game::~Game()
{
    for (auto block : qAsConst(*blocks)) {
        delete block;
    }
    blocks->clear();
    delete blocks;
    for (auto enemy : qAsConst(*enemies)) {
        delete enemy;
    }
    enemies->clear();
    delete enemies;
    for (auto portal : qAsConst(*portals)) {
        delete portal;
    }
    portals->clear();
    delete portals;
    for (auto arrow : qAsConst(*arrows)) {
        delete arrow;
    }
    arrows->clear();
    delete arrows;
    delete player;
    delete timer;
    world->clear();
    delete world;
    delete gameover;
    delete loadscreen;
    delete menu;
}
