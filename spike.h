#ifndef SPIKE_H
#define SPIKE_H

#include <enemy.h>
#include <sprite.h>
#include <QGraphicsPixmapItem>
class Spike : public Enemy
{
public:
    Spike(qreal posx, qreal posy,
          qreal spawnx, qreal spawny,
          int tMaxHealth = 9999,
          int atk = 10,
          short direction = 0,
          bool inmu = true,
          bool state = true,
          QGraphicsObject *parent = nullptr);
    virtual ~Spike() {};
    virtual void check() override;

private:
    virtual void dealDamage() override;
    virtual void attack() override;
    QPointF spawnPos;
};

#endif // SPIKE_H
