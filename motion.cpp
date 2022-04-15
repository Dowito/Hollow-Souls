#include "motion.h"
#include <macros.h>
Motion::Motion()
{
    a.setY(GRAVEDAD);
}

Motion::Motion(QPointF pos, QPointF vel, QPointF acc)
{
    this->r = pos;
    this->v = vel;
    this->a = acc;
}

Motion::Motion(qreal posx, qreal posy, qreal velx, qreal vely, qreal accx, qreal accy)
{
    r = {posx,posy};
    v = {velx,vely};
    a = {accx,accy};
}

void Motion::calculatePos()
{
    a.setY(*gravityTest);
    v = v+(a*periodo);
    r = r+(v*periodo);
}

void Motion::setPeriodo(qreal newPeriodo)
{
    periodo = newPeriodo;
}

void Motion::calculateAcelerationTest()
{
    a.setY(*gravityTest);
}

short Motion::getDirectionX() const
{
    return directionX;
}

void Motion::setAce(const QPointF &newA)
{
    a = newA;
}

void Motion::setAce(qreal ax, qreal ay)
{
    a = {ax, ay};
}

void Motion::setVel(const QPointF &newV)
{
    v = newV;
}

void Motion::setVel(qreal vx, qreal vy)
{
    v = {vx, vy};
}
