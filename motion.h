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
    Motion(QVector2D r, QVector2D v, QVector2D a, QObject *parent = nullptr);

    void setAce(const QVector2D &newA);
    void setVel(const QVector2D &newV);
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
    QVector2D a; //vector aceleracion
    QVector2D v; //vector velocidad
    QVector<Block*> *blocks;
    QTimer *timer;
};

#endif // MOTION_H
