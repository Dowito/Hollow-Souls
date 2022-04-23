#include "motionblock.h"
#include "player.h"
#include "enemy.h"
#include <QDebug>
MotionBlock::MotionBlock(qreal posx, qreal posy ,
                         unsigned int width, unsigned int height,
                         bool limitX, bool limitY,
                         qreal xmin, qreal xmax,
                         qreal ymin, qreal ymax,
                         qreal velx, qreal vely,
                         qreal accx, qreal accy)
    :Motion(posx, posy, velx, vely, accx, accy),
      Block(posx, posy, width, height, false)
{
    this->limitX = limitX;
    this->limitY = limitY;
    this->xmin = xmin;
    this->xmax = xmax;
    this->ymin = ymin;
    this->ymax = ymax;
    dezplazamiento = {0,0};
}

void MotionBlock::check()
{
    calculatePos();
    dezplazamiento = r - pos();
    setPos(r);
    collidesWithPlayer();
    checkLimits();
}

void MotionBlock::collidesWithPlayer()
{
    if (collidesWithItem(player)) {
        player->setPos(player->pos() + dezplazamiento);
        player->setRPos(player->pos());
    }
}

void MotionBlock::collidesWithEnemies()
{
    for (int i = 0; i<enemies->size(); i++) {
        if (collidesWithItem(enemies->at(i))) {
            enemies->at(i)->setPos(enemies->at(i)->pos() + dezplazamiento);
        }
    }
}

void MotionBlock::checkLimits()
{
    if(limitX){
        if(x() < xmin || x() > xmax) changeDirectionX();
    }
    if(limitY){
        if(y() < ymin || y() > ymax) changeDirectionY();
    }
}

void MotionBlock::changeDirectionX()
{
    v.setX((-1)*v.x());
}

void MotionBlock::changeDirectionY()
{
    v.setY((-1)*v.y());
}

void MotionBlock::setEnemies(QList<Enemy *> *newEnemies)
{
    enemies = newEnemies;
}

