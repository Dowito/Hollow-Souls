#include "fireball.h"
#include "audhulma.h"
FireBall::FireBall(Audhulma *audhulma):
    Explotion(audhulma->x()+60-48, audhulma->y()),
    Motion(audhulma->x()+60, audhulma->y()+48,
           0, 0,
           0, 0)
{
    loadSprite(":/new/sprites/sprites/explosion.png", 96,96);
    pot = 75;
    qreal velx = audhulma->getDirectionPlayer().x() * pot;
    qreal vely = audhulma->getDirectionPlayer().y() * pot;
    setVel({velx,vely});
    duration = 2000;
}

void FireBall::check()
{
    if(state){
        calculatePos();
        setPos(r.x()-48,r.y()-48);
        collidesWithPlayer();
        animation();
    }
    else {
        die();
    }
}
