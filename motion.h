#ifndef MOTION_H
#define MOTION_H
#include <macros.h>
#include <sprite.h>
#include <QVector2D>
#include <math.h>
#include <QtMath>
#include <QTimer>
extern float *gravityTest;
class Block;
class Motion : public Sprite
{
    Q_OBJECT
public:
    Motion(QObject *parent = nullptr);
    Motion(QPointF pos, QPointF vel, QPointF acc, QObject *parent = nullptr);

    void setAce(const QPointF &newA);
    void setAce(float ax, float ay);
    void setVel(const QPointF &newV);
    void setVel(float vx, float vy);
    void setPeriodo(float newPeriodo);
    void setBlocks(QVector<Block *> *newBlocks);
    short getDirectionX() const;

public slots:
    virtual void move();

protected:
    virtual void collisions();
    virtual void collisionsX();
    virtual void collisionsY();
    virtual void calculateAceleration();
    void calculateAcelerationTest();
    int speed;
    short directionX;
    float periodo;
    QPointF acc; //vector aceleracion
    QPointF vel; //vector velocidad
    QPointF pos; //vector posicion
    QVector<Block*> *blocks;
    QTimer *timer;
};

#endif // MOTION_H
