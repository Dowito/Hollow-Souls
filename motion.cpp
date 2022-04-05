#include "motion.h"
Motion::Motion()
{
    a.setY(GRAVEDAD);
    periodo = TTT;
}

Motion::Motion(QVector2D r, QVector2D v, QVector2D a)
{
    this->r = r;
    this->v = v;
    this->a = a;
}

void Motion::move()
{
    v = v+(a*periodo); //v = v+(a*TTT);
    r = r+(v*periodo); //v = v+(a*TTT);
    setPos(r.toPointF());
}

const QVector2D &Motion::getR() const
{
    return r;
}

void Motion::setPeriodo(float newPeriodo)
{
    periodo = newPeriodo;
}

void Motion::setA(const QVector2D &newA)
{
    a = newA;
}

void Motion::setV(const QVector2D &newV)
{
    v = newV;
}

void Motion::setR(const QVector2D &newR)
{
    r = newR;
}
