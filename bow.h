#ifndef BOW_H
#define BOW_H

#include "sprite.h"
#include <QGraphicsPixmapItem>
class Arrow;
class Enemy;
class Player;
class Bow : public Sprite, public QGraphicsPixmapItem
{
public:
    Bow();
    Bow(int atk, qreal pot, qreal angle);
    ~Bow() {};
    void shoot(QPointF posOwner); //dispara flecha

private:
    void calculateVelDir();
    int atk;
    qreal angle;
    qreal pot;
    QPointF velDir;
};

#endif // BOW_H
