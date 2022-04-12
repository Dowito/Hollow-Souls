#ifndef FURRY_H
#define FURRY_H

#include <enemy.h>
#include <motion.h>
#include <sprite.h>
#include <QGraphicsPixmapItem>
class Furry : public Enemy, public Motion
{
    Q_OBJECT
public:
    Furry(QGraphicsObject *parent);
    Furry(qreal posx, qreal posy, int maxHealth, int atk, short direction = 0);
    virtual void check() override;

private:
    //Mootion
    virtual void move() override;
    //Enemy
    virtual void attack() override;

    void changeDirectionX();
    int directionX;
};

#endif // FURRY_H
