#include "furry.h"

Furry::Furry(qreal posx, qreal posy, int maxHealth, int atk, short direction)
    :Enemy(posx, posy, maxHealth, atk, direction)
{
    loadSprite(":/new/sprites/sprites/furro.png");
    setPixmap(frames[this->direction][1]);
}

void Furry::check()
{
    move();
    //collisionsPlayer();
    //collisionsWeapon();
    //die();
}

void Furry::move()
{
    setPos(x()+1,y());
}

void Furry::attack()
{
    return;
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
