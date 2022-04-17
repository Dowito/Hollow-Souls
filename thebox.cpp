#include "thebox.h"
#include "ui_thebox.h"
#include <game.h>
#include <QTimer>
#include <player.h>
#include <block.h>
#include <healthbar.h>
#include <weapon.h>
#include <enemy.h>
#include <furry.h>
#include <demon.h>
#include <bow.h>
#include <arrow.h>
#include <circularmotion.h>
#include <dash.h>
#include <circularblock.h>
#include <motionblock.h>
#include <qdebug.h>
#include "Screens/world.h"
extern Game *game;
//variables estaticas
qreal *gravityTest = new qreal;
//motion
qreal Motion::periodo;
//enemigo
Player* Enemy::player;
QVector<Block*>* Enemy::blocks;
QList<Enemy*>* Enemy::enemies;
//arrow
Player *Arrow::player;
QVector<Block*> *Arrow::blocks;
QList<Enemy*> *Arrow::enemies;
QList<Arrow*> *Arrow::arrows;
//Dash
Player *Dash::player;
//Block
QVector<Block*> *Block::blocks;
//---------------------------
TheBox::TheBox(QWidget *parent) :
    QMainWindow(parent),
    clockMs(new unsigned int),
    scene(new QGraphicsScene),
    ui(new Ui::TheBox)
{
    //Variables estaticas de clases
    *gravityTest = GRAVEDAD;
    //Motion
    Motion::setPeriodo(TTT);
    //Enemy
    Enemy::setBlocks(game->blocks);
    Enemy::setEnemies(game->enemies);
    //Arrow
    Arrow::setEnemies(game->enemies);
    Arrow::setBlocks(game->blocks);
    Arrow::setArrows(game->arrows);
    //----------------------------------
    ui->setupUi(this);
    setGeometry(0,0,1280,720);
    ui->graphicsView->setGeometry(0,0,width(),height());
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->scene()->setSceneRect(0,0,ui->graphicsView->width(), ui->graphicsView->width());
    generateSandBox();
    //personaje
    scene->addItem(prueba = new Player);
    prueba->setPos(144,192);
    prueba->setWeapon(new Weapon(prueba));
    prueba->setHealthBar(new HealthBar(prueba));
    prueba->setBow(new Bow);
    prueba->setDash(new Dash);
    prueba->setCarcaj(1);
    scene->addItem(prueba->getBow());
    scene->addItem(prueba->getDash());
    game->player = prueba;
    Enemy::setPlayer(game->player);
    Arrow::setPlayer(game->player);
    Dash::setPlayer(game->player);
    //Enemigo
    scene->addItem(new Demon(288,288,-24));
    scene->addItem(new Demon(144,288,-24));
    scene->addItem(new Demon(480,288,100));
    scene->addItem(new Furry(192,288));
    scene->addItem(new Furry(144,288,50));
    //Boques con movimiento
    CircularBlock *testCircularBlock = new CircularBlock(8*48, 9*48, 48*5, 48, 96, 3, 0.1);
    game->blocks->push_back(testCircularBlock);
    scene->addItem(testCircularBlock);
    MotionBlock *testMotionBlock = new MotionBlock(4*48, 4*48, 50*3, 50, 10);
    game->blocks->push_back(testMotionBlock);
    scene->addItem(testMotionBlock);
    game->world->loadWorld(1);
    game->world = new World(1900, 450);
    game->world->loadWorld(0);
    scene = game->world;
    Block::setBlocks(game->blocks);
    //connect(game->timer, SIGNAL(timeout()), testCircular, SLOT(move()));
    //game->timer->stop();
}


void TheBox::generateCol(int num, int mx, int my)
{
    for (int i = 0; i<num; i++) {
        game->blocks->push_back(new Block({static_cast<qreal>(mx)*50, static_cast<qreal>((my+i)*50)}, 50, 50));
    }
}

void TheBox::generateFil(int num, int mx, int my)
{
    for (int i = 0; i<num; i++) {
        game->blocks->push_back(new Block({static_cast<qreal>((mx+i)*50), static_cast<qreal>(my*50)}, 50, 50));
    }
}

void TheBox::generateSandBox()
{
    //generateCol(13,1,1);
    //generateCol(13,20,0);
    //generateFil(20,7,9);
    //generateFil(16,3,2);
    //generateFil(20,1,11);
    //generateGrid();
    for (int i = 0; i<game->blocks->size();i++ ) {
        scene->addItem(game->blocks->at(i));
        game->blocks->at(i)->setBrush(QBrush(Qt::cyan));
    }
}

void TheBox::generateGrid()
{
    for (int i = 0; i< 1280/(50*GAME_SCALE); i++) {
        for (int j = 0; j< 720/(50*GAME_SCALE); j++) {
            scene->addItem(new Block({static_cast<qreal>(i*(50*GAME_SCALE)), static_cast<qreal>(j*(50*GAME_SCALE))}, (50*GAME_SCALE), (50*GAME_SCALE)));
        }
    }
}

Ui::TheBox *TheBox::getUi() const
{
    return ui;
}

void TheBox::on_ZoomPlus_clicked()
{
    ui->graphicsView->scale(1.2,1.2);
}

void TheBox::on_ZoomMinus_clicked()
{
    ui->graphicsView->scale(0.8,0.8);
}

void TheBox::on_Iniciar_clicked()
{
    ui->Ingresar->setEnabled(false);
    ui->rX->setEnabled(false);
    ui->rY->setEnabled(false);
    ui->rVx->setEnabled(false);
    ui->rVy->setEnabled(false);
    ui->rax->setEnabled(false);
    ui->ray->setEnabled(false);
    ui->rClockMs->setEnabled(false);
    prueba->setPos({static_cast<float>(ui->rX->value()),static_cast<float>(ui->rY->value())});
    prueba->setVel({static_cast<float>(ui->rVx->value()),static_cast<float>(ui->rVy->value())});
    //prueba->setAce({static_cast<float>(ui->rax->value()),static_cast<float>(ui->ray->value())});
    *gravityTest = ui->ray->value();
    prueba->setPeriodo(ui->rPeriodo->value());
    *clockMs = ui->rClockMs->value();
    prueba->setFocus();
    game->timer->start(*clockMs);
}


void TheBox::on_Detener_clicked()
{
    game->timer->stop();
    ui->Ingresar->setEnabled(true);
    ui->rX->setEnabled(true);
    ui->rY->setEnabled(true);
    ui->rVx->setEnabled(true);
    ui->rVy->setEnabled(true);
    ui->rax->setEnabled(true);
    ui->ray->setEnabled(true);
    ui->rClockMs->setEnabled(true);
}


void TheBox::on_Ingresar_clicked()
{
    prueba->setPos({static_cast<float>(ui->rX->value()),static_cast<float>(ui->rY->value())});
    prueba->setVel({static_cast<float>(ui->rVx->value()),static_cast<float>(ui->rVy->value())});
    prueba->setAce({static_cast<float>(ui->rax->value()),static_cast<float>(ui->ray->value())});
    prueba->setPeriodo(ui->rPeriodo->value());
    *clockMs = ui->rClockMs->value();
}


void TheBox::on_Left_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x()-10,
                                            ui->graphicsView->scene()->sceneRect().y(),
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_Right_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x()+10,
                                            ui->graphicsView->scene()->sceneRect().y(),
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_Up_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x(),
                                            ui->graphicsView->scene()->sceneRect().y()-10,
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}


void TheBox::on_pushButton_2_clicked()
{
    ui->graphicsView->scene()->setSceneRect(ui->graphicsView->scene()->sceneRect().x(),
                                            ui->graphicsView->scene()->sceneRect().y()+10,
                                            ui->graphicsView->scene()->sceneRect().width(),
                                            ui->graphicsView->scene()->sceneRect().height());
}

void TheBox::on_pushButton_clicked()
{
    prueba->setRotation(prueba->rotation()+45);
}

TheBox::~TheBox()
{
    delete ui;
    delete prueba;
    delete gravityTest;
    delete clockMs;
    scene->clear();
    delete scene;
}
