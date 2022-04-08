#include "motion.h"
#include <block.h>
Motion::Motion()
{
    a.setY(GRAVEDAD);
    periodo = TTT;
}

Motion::Motion(QVector2D r, QVector2D v, QVector2D a)
{
    setPos(r.toPointF());
    this->v = v;
    this->a = a;
}

void Motion::move()
{
    //calculateAceleration();
    v = v+(a*periodo); //v = v+(a*TTT);
    setPos(pos() + v.toPointF()); //v = v+(a*TTT);
    collisions();
}

void Motion::collisions()
{
    for (int i = 0; i < blocks->size(); i++){
        if(pos().x() < blocks->at(i)->rect().width()) {
            v.setX(v.x()*(-1));
        }
        else if (pos().x() + boundingRect().width() > blocks->at(i)->pos().x()) {
            v.setX(v.x()*(-1));
        }
    }
}

void Motion::calculateAceleration()
{
    a = {0, GRAVEDAD};
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
