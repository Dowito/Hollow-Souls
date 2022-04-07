#ifndef MOTION_H
#define MOTION_H
#include <macros.h>
#include <sprite.h>
#include <QVector2D>
#include <math.h>
#include <QTimer>
class Motion : public Sprite
{
    Q_OBJECT
public:
    Motion();
    Motion(QVector2D r, QVector2D v, QVector2D a);

    void setAce(const QVector2D &newA);
    void setVel(const QVector2D &newV);
    void setPeriodo(float newPeriodo);

public slots:
    virtual void move();

protected:
    float periodo;
    QVector2D a; //vector aceleracion
    QVector2D v; //vector velocidad
};

#endif // MOTION_H
