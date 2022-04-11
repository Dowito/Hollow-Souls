#ifndef CIRCULARMOTION_H
#define CIRCULARMOTION_H

#include <motion.h>
class CircularMotion : public Motion
{
public:
    CircularMotion();
    CircularMotion(float posx, float posy,
                   float radio,
                   unsigned short direction,
                   float angularVel,
                   float angularAcc = 0);
    /*
    CircularMotion(float posx, float posy,
                   float radio,
                   float angularPos,
                   float angularVel,
                   float angularAcc = 0);
    */
    virtual void move() override;

protected:
    void calculateAngle();
    QPointF calculatePos();
    void calculateAceleration();
    void calculateAccTangential();
    void calculateAccNormal();
    float radio;
    float angularAcc;
    float angularVel;
    float angularPos;
    QPointF accTangential, uniTangential;
    QPointF accNormal, uniNormal;
};

#endif // CIRCULARMOTION_H
