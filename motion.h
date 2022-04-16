#ifndef MOTION_H
#define MOTION_H
#include <QtMath>
#include <QPointF>
#include <macros.h>
extern qreal *gravityTest;
class Motion
{
public:
    Motion();
    Motion(QPointF pos, QPointF vel, QPointF acc);
    Motion(qreal posx, qreal posy,
           qreal velx = 0, qreal vely = 0,
           qreal accx = 0, qreal accy = *gravityTest);
    virtual ~Motion() {};

    void setAce(const QPointF &newA);
    void setAce(qreal ax, qreal ay);
    void setVel(const QPointF &newV);
    void setVel(qreal vx, qreal vy);
    static void setPeriodo(qreal newPeriodo);

    QPointF getRPos() const;
    void setRPos(QPointF newR);

    QPointF getVel() const;

protected:
    /*!
     * \brief calculatePos actualiza los vectores a, v y a para el siguiente instante de "tiempo".
     */
    virtual void calculatePos(); //funcion que actualiza los vectores a, v y r, luegos e actualiza la Pos de la scene con rpero en otra clase.
    int speed; //magnitud del vector velocidad, esto tambien sobra. Tambien tocaria darle una direcction.
    QPointF a; //vector aceleracion
    QPointF v; //vector velocidad
    QPointF r; //vector posicion
    static qreal periodo;
    void calculateAcelerationTest();
};

#endif // MOTION_H
