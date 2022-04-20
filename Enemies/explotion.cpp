#include "explotion.h"
#include "demon.h"
Explotion::Explotion(Demon *demon)
    :Enemy(0, demon->y(), 9999, 30, demon->getDirection(), true, true, nullptr)
{
    static int num = 0;
    control = num;
    num++;
    label = "Explotion";
    qDebug() << "explotion " << control;
    loadSprite(":/new/sprites/sprites/explosion.png", 96,96);
    qreal posx;
    (demon->getDirection()==1) ? posx = demon->x()-w : posx = demon->x()+w;
    setX(posx);
    setPixmap(frames[0][2]);
}

void Explotion::check()
{
    if(state){
        collidesWithPlayer();
        animation();
    }
    else {
        qDebug() << "explotion " << control;
        die();
    }
}

void Explotion::animation()
{
    if(stepsDie >= 120){
        state = false;
    }
    else stepsDie++;
}

void Explotion::attack()
{
    return;
}
