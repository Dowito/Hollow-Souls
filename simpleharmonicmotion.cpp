#include "simpleharmonicmotion.h"

SimpleHarmonicMotion::SimpleHarmonicMotion(qreal amplitud, qreal frequency, qreal phase, qreal velx)
{
    r.setX(0);
    v.setX(velx);
    this->amplitud = amplitud;
    this->frequency = frequency;
    this->phase = phase;
}

void SimpleHarmonicMotion::calculatePos()
{
    calculatePosX();
    calculatePosY();
}

void SimpleHarmonicMotion::calculatePosX()
{
    r.setX(r.x()+(v.x()*periodo));
}

void SimpleHarmonicMotion::calculatePosY()
{
    r.setY(amplitud*qSin(frequency*r.x()+phase));
}


