#ifndef CIRCULARMOTION_H
#define CIRCULARMOTION_H

#include <motion.h>
class CircularMotion : public Motion
{
    Q_OBJECT
public:
    CircularMotion();
    CircularMotion(float posx, float posy,
                   float radio,
                   float angularPos,
                   float angularVel,
                   float angularAcc = 0,
                   float speedIni = 0);

public slots:
    virtual void move() override;

protected:
    void calculateAngle();
    void calculateAceleration() override;
    void calculateAccTangential();
    void calculateAccNormal();
    float radio;
    float angularAcc;
    float angularVel;
    float angularPos;
    QVector2D accTangential, uniTangential;
    QVector2D accNormal, uniNormal;
};

#endif // CIRCULARMOTION_H
