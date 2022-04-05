#include "motion.h"
Motion::Motion()
{
    a = {0,GRAVEDAD};
}

Motion::Motion(QVector2D r, QVector2D v, QVector2D a)
{
    this->r = r;
    this->v = v;
    this->a = a;
}

void Motion::move()
{
    v = v+(a*TTT);
    r = r+(v*TTT);
    setPos(r.toPointF());
}
