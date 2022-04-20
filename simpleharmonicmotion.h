#ifndef SIMPLEHARMONICMOTION_H
#define SIMPLEHARMONICMOTION_H

#include "motion.h"
class SimpleHarmonicMotion : public Motion
{
public:
    SimpleHarmonicMotion(qreal amplitud, qreal frequency, qreal phase, qreal velx);

protected:
    virtual void calculatePosX();
    virtual void calculatePosY();
    qreal amplitud;
    qreal frequency;
    qreal phase;
    // Motion interface
protected:
    virtual void calculatePos() override;
};

#endif // SIMPLEHARMONICMOTION_H
