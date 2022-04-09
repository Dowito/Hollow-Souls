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

    /* Codigo de TheBox
    #include "thebox.h"
    #include "ui_thebox.h"
    #include <game.h>
    #include <QTimer>
    #include <player.h>
    #include <block.h>
    #include <healthbar.h>
    #include <weapon.h>
    #include <enemy.h>
    extern Game *game;
    float *gravityTest = new float;
    TheBox::TheBox(QWidget *parent) :
        QMainWindow(parent),
        clockMs(new unsigned int),
        scene(new QGraphicsScene),
        ui(new Ui::TheBox)
    {
        *gravityTest = GRAVEDAD;
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
        //enemigo
        scene->addItem(pruebaColli = new Enemy(":/new/sprites/sprites/hombre_lobo.png", 240, 240));
        //game->timer->stop();
    }
    */
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
