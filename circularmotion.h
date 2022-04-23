#ifndef CIRCULARMOTION_H
#define CIRCULARMOTION_H

#include <motion.h>
class CircularMotion : public Motion
{
public:
    CircularMotion();
    CircularMotion(float radio,
                   float angularVel,
                   float angularAcc = 0);
    /*
    CircularMotion(float radio,
                   float angularPos,
                   float angularVel,
                   float angularAcc = 0);
    */
    virtual ~CircularMotion() {};

protected:
    virtual void calculatePos() override;
    void calculateAngle();
    void calculateAccTangential();
    void calculateAccNormal();
    void calculateAceleration(); //calcula la aceleracion la cual es aT + aN
    float radio;
    float angularAcc;
    float angularVel;
    float angularPos;
    QPointF accTangential, uniTangential; //aceleracion y vector direccion tangencial: este vector define la direccion de la velocidad.
    QPointF accNormal, uniNormal; //acelarcion normal y vector direccion de normal
};

#endif // CIRCULARMOTION_H
