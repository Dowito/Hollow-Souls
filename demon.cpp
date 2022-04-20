#include "demon.h"
#include "Enemies/explotion.h"
Demon::Demon(qreal posx, qreal posy, short direction)
    :Enemy(posx, posy, 90, 50, direction)
{
    static unsigned int num = 0;
    loadSprite(":/new/sprites/sprites/demonio.png"); //puedo llamar un constructor de sprite y que use la funcion virtual definida en esta
    setPixmap(frames[this->direction][1]);
    setScale(2);
    delay = 0;
    control = num;
    num++;
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
        qDebug() << "Demonio: " << control;
        scene()->addItem(new Explotion(this));
        delay = 0;
    }
    else delay++;
}
