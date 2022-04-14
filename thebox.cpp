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
#include <arrow.h>
#include <circularmotion.h>
#include <qdebug.h>
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
    //Arrow::setEnemies(game->enemies);
    //Arrow::setBlocks(game->blocks);
    //Arrow::setArrows(game->arrows);
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
    game->player = prueba;
    Enemy::setPlayer(game->player);
    Arrow::setPlayer(game->player);
    //Enemigo
    scene->addItem(new Demon(288,288,-24));
    scene->addItem(new Demon(144,288,-24));
    scene->addItem(new Demon(480,288,100));
    scene->addItem(new Furry(190,288));
    scene->addItem(new Furry(144,280));
    //CircularMotion *testCircular = new CircularMotion(48*5, 48*11, 48*7, 1, 0.01);
    //scene->addItem(testCircular);
    //connect(game->timer, SIGNAL(timeout()), testCircular, SLOT(move()));
    //game->timer->stop();
}


void TheBox::generateCol(int num, int mx, int my)
{
    for (int i = 0; i<num; i++) {
        game->blocks->push_back(new Block({static_cast<qreal>(mx)*SIZE_BLOCK, static_cast<qreal>((my+i)*SIZE_BLOCK)}, SIZE_BLOCK, SIZE_BLOCK));
    }
}

void TheBox::generateFil(int num, int mx, int my)
{
    for (int i = 0; i<num; i++) {
        game->blocks->push_back(new Block({static_cast<qreal>((mx+i)*SIZE_BLOCK), static_cast<qreal>(my*SIZE_BLOCK)}, SIZE_BLOCK, SIZE_BLOCK));
    }
}

void TheBox::generateSandBox()
{
    generateCol(13,1,1);
    generateCol(13,20,0);
    generateFil(16,3,2);
    generateFil(20,1,11);
    generateGrid();
    for (int i = 0; i<game->blocks->size();i++ ) {
        scene->addItem(game->blocks->at(i));
        game->blocks->at(i)->setBrush(QBrush(Qt::cyan));
    }
}

void TheBox::generateGrid()
{
    for (int i = 0; i< 1280/(SIZE_BLOCK*GAME_SCALE); i++) {
        for (int j = 0; j< 720/(SIZE_BLOCK*GAME_SCALE); j++) {
            scene->addItem(new Block({static_cast<qreal>(i*(SIZE_BLOCK*GAME_SCALE)), static_cast<qreal>(j*(SIZE_BLOCK*GAME_SCALE))}, (SIZE_BLOCK*GAME_SCALE), (SIZE_BLOCK*GAME_SCALE)));
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
