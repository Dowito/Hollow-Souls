#ifndef MOTION_H
#define MOTION_H
#include <QtMath>
#include <QPointF>
extern float *gravityTest;
class Motion
{
public:
    Motion();
    Motion(QPointF pos, QPointF vel, QPointF acc);

    void setAce(const QPointF &newA);
    void setAce(float ax, float ay);
    void setVel(const QPointF &newV);
    void setVel(float vx, float vy);
    void setPeriodo(float newPeriodo);
    short getDirectionX() const;

    virtual void move();

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
