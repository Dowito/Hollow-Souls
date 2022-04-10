#include "motion.h"
#include <block.h>
#include <QDebug>
Motion::Motion(QObject *parent)
    :Sprite(parent)
{
    acc.setY(GRAVEDAD);
    periodo = TTT;
}

Motion::Motion(QPointF pos, QPointF vel, QPointF acc, QObject *parent)
    :Sprite(parent)
{
    setPos(pos);
    this->vel = vel;
    this->acc = acc;
}

void Motion::move()
{
    calculateAceleration();
    vel = vel+(acc*periodo); //v = v+(a*TTT);
    //setPos(pos() + v.toPointF()); //v = v+(a*TTT);
    setY(y() + vel.y());
    collisionsY();
    setX(x() + vel.x());
    collisionsX();
}

void Motion::collisions()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            /*
            if(pos().x() < blocks->at(i)->pos().x() + blocks->at(i)->rect().width()) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
                v.setX(v.x()*(-1));
            }
            else if (pos().x() + boundingRect().width() > blocks->at(i)->pos().x()) {
                setX(blocks->at(i)->x() - boundingRect().width() - 1);
                v.setX(v.x()*(-1));
            }
            */
        }
    }
}

void Motion::collisionsX()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if (vel.x()<0) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
            }
            else if (vel.x()>0) {
                setX(blocks->at(i)->x() - w - 1);
            }
            directionX *= (-1);
            //v.setX(v.x()*(-1));
            vel.setX(vel.x()*directionX);
        }
    }
}

void Motion::collisionsY()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (vel.y() <= 0) { //si colisiona hacia arriba
                setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
            }
            else { //si colisiona hacia abajo
                setY(blocks->at(i)->y() - h -1);
            }
            vel.setY(0);
            vel.setX(speed*directionX);
        }
    }
}

void Motion::calculateAceleration()
{
    acc = {0, GRAVEDAD};
}

void Motion::calculateAcelerationTest()
{
    acc.setY(*gravityTest);
}

short Motion::getDirectionX() const
{
    return directionX;
}

void Motion::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
}

void Motion::setPeriodo(float newPeriodo)
{
    periodo = newPeriodo;
}

void Motion::setAce(const QPointF &newA)
{
    acc = newA;
}

void Motion::setVel(const QPointF &newV)
{
    vel = newV;
}

void Motion::setVel(float vx, float vy)
{
    vel = {vx, vy};
}
