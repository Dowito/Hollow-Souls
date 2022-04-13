#ifndef CIRCULARMOTION_H
#define CIRCULARMOTION_H

#include <motion.h>
class CircularMotion : public Motion
{
public:
    CircularMotion();
    /*!
     * \brief CircularMotion
     * \param posx posicion en x
     * \param posy posicion en y
     * \param radio a mayor radio
     * \param direction 0=arriba->abajo, 1=izquierda->derecha, 2=derecha->izquierda, 3=abajo->arriba
     * \param angularVel +vel->sentido antihorario, -vel->sentido horario.
     * mientras mayor sea el valor absoluto de vel, a mayor velocidad se movera.
     * \param angularAcc aumento de la velocidad angulor por unidad de tiempo.
     */
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
