#include "planet.h"
Planet::Planet()
{
    a = {0,GRAVEDAD};
}

Planet::Planet(QVector2D r, QVector2D v, QVector2D a)
{
    this->r = r;
    this->v = v;
    this->a = a;
}

void Planet::move()
{
    v = v+(a*TTT);
    r = r+(v*TTT);
    setPos(r.toPointF());
}
