#include "game.h"
#include <motion.h>
#include <QTimer>
Game::Game(QWidget *parent):
    timer(new QTimer)
{
    setParent(parent);
    setGeometry(0,0,1280,720);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setScene(new QGraphicsScene);
    scene()->setSceneRect(0,0,width(),height());
    prueba = new Motion;
    prueba->setSprite(":/new/sprites/sprites/hombre_lobo.png");
    prueba->setSize(48,48);
    prueba->setFrame(1);
    prueba->setPos(360,360);
    connect(timer, SIGNAL(timeout()), prueba, SLOT(move()));
    scene()->addItem(prueba);
    //timer->start(CLOCK_GAME);
}
