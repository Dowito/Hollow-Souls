#ifndef CIRCULARBLOCK_H
#define CIRCULARBLOCK_H

#include <circularmotion.h>
#include <block.h>
class CircularBlock : public Block, public CircularMotion
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
    CircularBlock(qreal posx, qreal posy,
                  unsigned int width,
                  unsigned int height,
                  float radio,
                  unsigned short direction,
                  float angularVel,
                  float angularAcc = 0);
protected:
    virtual void check() override;
};

#endif // CIRCULARBLOCK_H
