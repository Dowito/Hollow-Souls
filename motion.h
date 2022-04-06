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

    void setR(const QVector2D &newR);

    void setA(const QVector2D &newA);
    void setV(const QVector2D &newV);

    void setPeriodo(float newPeriodo);

    const QVector2D &getR() const;

public slots:
    virtual void move();

protected:
    float periodo;
    QVector2D a; //vector aceleracion
    QVector2D v; //vector velocidad
    QVector2D r; //vector posicion
};

#endif // MOTION_H
