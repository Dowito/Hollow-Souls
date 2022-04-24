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
#include "Utilities/fairy.h"
#include <healthbar.h>
#include "Utilities/portal.h"
#include "Screens/gameover.h"
#include "Screens/menu.h"
#include <QGraphicsRectItem>
#include "Screens/userwindow.h"
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
//Menu
Game *Menu::game;
//UserWindow
Game *UserWindow::game;

Game::Game(QWidget *parent):
    timer(new QTimer),
    blocks(new QVector<Block*>),
    portals(new QVector<Portal*>),
    enemies(new QList<Enemy*>),
    arrows(new QList<Arrow*>),
    world(new World(this))
{
    //iniciando variables esticas
    initStaticVar();
    //iniciando GraphicsView aka game
    setParent(parent);
    setGeometry(160,90,1280,720);
    setSceneRect(0,0,1280,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1280,720);
    //iniciando Fairy
    Fairy *fairy = new Fairy(0, 11*SB, 4*SB);
    world->addItem(fairy);
    fairy->initText();
    //iniciando player
    player = new Player;
    player->setBlocks(blocks);
    player->setHealthBar(new HealthBar(player));
    player->setWeapon(new Weapon(player));
    player->setDash(new Dash);
    player->setBow(new Bow);
    player->setFairy(fairy);
    world->initPlayer();
    Dash::setPlayer(player);
    Arrow::setPlayer(player);
    Enemy::setPlayer(player);
    MotionBlock::setPlayer(player);
    Portal::setPlayer(player);
    //Menu
    menu = new Menu;
    menu->setGame(this);
    setScene(menu);
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

void Game::loadNextWorld(unsigned short world, qreal posx, qreal posy)
{
    timer->stop();
    disconnect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    player->clearFocus();
    setScene(nullptr);//poner pantalla de carga.
    this->world->loadWorld(world, {posx,posy});
    setScene(this->world);
    player->setFocus();
    connect(timer, SIGNAL(timeout()), this, SLOT(timeWorld()));
    timer->start(CLOCK_GAME);
}

void Game::newGame()
{
    player->setUser(user);
    player->setDifficulty(difficulty);
    player->getBow()->setIfEquip(false);
    loadNextWorld(0, 11*SB+100, 4*SB+100);
}

void Game::loadGame()
{
    string info = readArchivo("../HollowSouls/save_games/saves.txt");
    info.pop_back();
    string world, posx, posy, bow;
    int index = info.find(user.toStdString());
    index = info.find(' ', index);
    index += 1;
    world = info.substr(index, info.find(' ', index)-index);
    index = info.find(' ', index);
    index += 1;
    posx = info.substr(index, info.find(' ', index)-index);
    index = info.find(' ', index);
    index += 1;
    posy = info.substr(index, info.find(' ', index)-index);
    index = info.find(' ', index);
    index += 1;
    bow = info.substr(index, info.find('\n', index)-index);
    player->setUser(user);
    player->setDifficulty(difficulty);
    player->setPos(stof(posx), stof(posy));
    player->getBow()->setIfEquip(stoi(bow));
    loadNextWorld(stoi(world), stof(posx), stof(posy));
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
    //Menu
    Menu::setGame(this);
    //UserWindow
    UserWindow::setGame(this);
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
    menu->clear();
    delete menu;
    delete gameover;
}
