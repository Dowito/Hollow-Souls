#include "motionblock.h"
#include <QDebug>
MotionBlock::MotionBlock(qreal posx, qreal posy ,
                         unsigned int width, unsigned int height,
                         qreal velx, qreal vely,
                         qreal accx, qreal accy,
                         QObject *parent):
    Motion(posx, posy, velx, vely, accx, accy),
    Block(posx, posy, width, height, parent)
{

}

void MotionBlock::check()
{
    calculatePos();
    setPos(r);
}
