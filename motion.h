#ifndef MOTION_H
#define MOTION_H
#include <macros.h>
#include <sprite.h>
#include <QVector2D>
#include <math.h>
class Motion : public Sprite
{
    Q_OBJECT
public:
    Motion();
    Motion(QVector2D r, QVector2D v, QVector2D a);

private slots:
    void move();

private:
    QVector2D a; //vector aceleracion
    QVector2D v; //vector velocidad
    QVector2D r; //vector posicion
};

#endif // MOTION_H