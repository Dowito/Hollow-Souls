#include "motion.h"
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
    v = v+(a*periodo); //v = v+(a*TTT);
    setPos(pos() + v.toPointF()); //v = v+(a*TTT);
}

void Motion::collisions()
{

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
