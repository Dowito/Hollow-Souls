#include "bow.h"
#include <player.h>
#include <QGraphicsScene>
#include <QtMath>
#include <arrow.h>
#include <QGraphicsRectItem>
#include <QDebug>
Bow::Bow()
{
    loadSprite(":/new/sprites/sprites/Bow - left.png", 96, 48, 1, 3);
    loadSprite(":/new/sprites/sprites/Bow - right.png", 96, 48, 1, 3);
    setVisible(false);
    pot = 150.0;
    angle = -10.0;
    atk = 15;
    ifEquip = true;
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
    scene()->addItem(new Arrow(x() + (48/2), y() + (48/2) , pot*velDir.x(), pot*velDir.y(), atk));
}

void Bow::animation()
{
    if(isVisible()){
        if(stepsAnimation == 20){
            stepsAnimation = 0;
            setVisible(false);
        }else stepsAnimation++;
    }
}

void Bow::calculateVelDir()
{
    velDir.setX(qCos(qDegreesToRadians(angle)));
    velDir.setY(qSin(qDegreesToRadians(angle)));
}

bool Bow::getIfEquip() const
{
    return ifEquip;
}

void Bow::setIfEquip(bool newIfEquip)
{
    ifEquip = newIfEquip;
}
