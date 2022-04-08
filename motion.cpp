#include "motion.h"
#include <block.h>
#include <QDebug>
Motion::Motion(QObject *parent)
    :Sprite(parent)
{
    a.setY(GRAVEDAD);
    periodo = TTT;
}

Motion::Motion(QVector2D r, QVector2D v, QVector2D a, QObject *parent)
    :Sprite(parent)
{
    setPos(r.toPointF());
    this->v = v;
    this->a = a;
}

void Motion::move()
{
    calculateAceleration();
    v = v+(a*periodo); //v = v+(a*TTT);
    //setPos(pos() + v.toPointF()); //v = v+(a*TTT);
    setY(y() + v.y());
    collisionsY();
    setX(x() + v.x());
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
            if (v.x()<0) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
            }
            else if (v.x()>0) {
                setX(blocks->at(i)->x() - w - 1);
            }
            directionX *= (-1);
            //v.setX(v.x()*(-1));
            v.setX(v.x()*directionX);
        }
    }
}

void Motion::collisionsY()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (v.y() <= 0) { //si colisiona hacia arriba
                setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
            }
            else { //si colisiona hacia abajo
                setY(blocks->at(i)->y() - h -1);
            }
            v.setY(0);
            v.setX(speed*directionX);
        }
    }
}

void Motion::calculateAceleration()
{
    a = {0, GRAVEDAD};
}

void Motion::calculateAcelerationTest()
{
    a.setY(*gravityTest);
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

void Motion::setAce(const QVector2D &newA)
{
    a = newA;
}

void Motion::setVel(const QVector2D &newV)
{
    v = newV;
}

void Motion::setVel(float vx, float vy)
{
    v = {vx, vy};
}
