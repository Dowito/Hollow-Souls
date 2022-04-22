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
    Bow(); //arco por defecto para el jugador.
    Bow(int atk, qreal pot, qreal angle);
    ~Bow() {};
    void shoot(QPointF posOwner, short direction); //dispara flecha
    void animation();

    bool getIfEquip() const;
    void setIfEquip(bool newIfEquip);

private:
    void calculateVelDir();
    int atk;
    unsigned int stepsAnimation;
    qreal angle;
    qreal pot;
    bool ifEquip;
    QPointF velDir;
};

#endif // BOW_H
