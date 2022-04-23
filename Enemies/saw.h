#ifndef SAW_H
#define SAW_H

#include "enemy.h"
#include "circularmotion.h"
class Saw : public Enemy, public CircularMotion
{
public:
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
    Saw(qreal posx, qreal posy,
        unsigned int width,
        unsigned int height,
        float radio,
        unsigned short direction,
        float angularVel,
        qreal scale = 1,
        float angularAcc = 0);

    Saw(qreal oposx, qreal oposy,
        qreal scale,
        qreal radio,
        qreal angularPos,
        qreal angularVel,
        qreal angularAcc = 0);
    virtual ~Saw() {};

private:
    void move();

    // Motion interface
public:
    void check();

    // Enemy interface
protected:
    void attack();
};

#endif // SAW_H
