#include "demon.h"

Demon::Demon(qreal posx, qreal posy, short direction)
    :Enemy(posx, posy, 120, 50, direction)
{
    loadSprite(":/new/sprites/sprites/demonio.png"); //puedo llamar un constructor de sprite y que use la funcion virtual definida en esta
    setPixmap(frames[this->direction][1]);
}

void Demon::check()
{
    if(state){
        collidesWithPlayer();
        collidesWithWeapon();
    }
    else die();
    return;
}

void Demon::attack()
{
    return;
}
