#include "demon.h"
#include "Enemies/explotion.h"
Demon::Demon(qreal posx, qreal posy, short direction)
    :Enemy(posx, posy, 30, 17, direction)
{
    loadSprite(":/new/sprites/sprites/demonio.png"); //puedo llamar un constructor de sprite y que use la funcion virtual definida en esta
    setPixmap(frames[this->direction][1]);
    setScale(2);
    delay = 0;
}

void Demon::check()
{
    if(state){
        collidesWithPlayer();
        collidesWithWeapon();
        attack();
    }
    else die();
}

void Demon::attack()
{
    if(delay >= 500){
        scene()->addItem(new Explotion(this));
        delay = 0;
    }
    else delay++;
}
