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
    Motion(qreal posx, qreal posy, qreal velx = 0, qreal vely = 0, qreal accx = 0, qreal accy = *gravityTest);

    void setAce(const QPointF &newA);
    void setAce(qreal ax, qreal ay);
    void setVel(const QPointF &newV);
    void setVel(qreal vx, qreal vy);
    void setPeriodo(qreal newPeriodo);
    short getDirectionX() const;

    virtual void move() = 0;

protected:
    virtual void collisions();
    virtual void collisionsX();
    virtual void collisionsY();
    void calculateAcelerationTest();
    int speed;
    short directionX;
    float periodo;
    QPointF a; //vector aceleracion
    QPointF v; //vector velocidad
    QPointF r; //vector posicion
};

#endif // MOTION_H
