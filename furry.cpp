#include "furry.h"

Furry::Furry(qreal posx, qreal posy, int maxHealth, int atk, QGraphicsObject *parent)
    :Enemy(posx, posy, maxHealth, atk)
{
    setParent(parent);
    loadSprite(":/new/sprites/sprites/furro.png");
    setPixmap(frames[0][1]);
}



/*
void Enemy::changeDirectionX()
{
    if(directionX < 0){ //izquierda
        if(scene()->items({x()-2, y()+h+2}).isEmpty()) directionX *= (-1); //solucion momentanea.
    }
    else {
        if(scene()->items({x()+w+2, y()+h+2}).isEmpty()) directionX *= (-1);
    }
}
*/
