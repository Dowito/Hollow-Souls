#include "bow.h"
#include <player.h>
#include <QGraphicsScene>
#include <QtMath>
//#include <arrow.h>
#include <QGraphicsEllipseItem>
#include <QDebug>
Bow::Bow()
{
    loadSprite(":/new/sprites/sprites/Bow - left.png", 96, 48, 1, 3);
    loadSprite(":/new/sprites/sprites/Bow - right.png", 96, 48, 1, 3);
    setPixmap(frames[1][1]);
    setVisible(false);
    pot = -30.0;
    angle = 30.0;
    atk = 20;
}

Bow::Bow(int atk, qreal pot, qreal angle)
{
    this->pot = pot;
    this->angle = angle;
    this->atk = atk;
}

void Bow::shoot(QPointF posOwner, short direction)
{
    setPixmap(frames[direction-1][1]);
    setVisible(true);
    calculateVelDir();
    if(direction == 2) { //derecha
        setPos(posOwner);
    }
    else{ //Izquierda
        setPos(posOwner.x()-((w/2)+3*GAME_SCALE), posOwner.y());
        velDir.setX(velDir.x()*(-1));
    }
    QGraphicsEllipseItem *prueba = new QGraphicsEllipseItem(0,0,40,40);
    prueba->setPos(pos());
    scene()->addItem(prueba);
    //scene()->addItem(new Arrow(posOwner.x(), posOwner.y(), pot*velDir.x(), pot*velDir.y(), atk));
}

void Bow::calculateVelDir()
{
    velDir.setX(qCos(qDegreesToRadians(angle)));
    velDir.setY(qSin(-qDegreesToRadians(angle)));
}

/*
void Bow::loadSprite(QString nameLeft, QString nameRight, unsigned int w, unsigned int h, unsigned short fil, unsigned short col)
{
    Sprite::loadSprite(nameLeft, w, h, fil, col);
    Sprite::loadSprite(nameRight, w, h, fil, col);
}
*/
