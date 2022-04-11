#ifndef FURRY_H
#define FURRY_H

#include <enemy.h>
#include <motion.h>
#include <sprite.h>
#include <QGraphicsPixmapItem>
class Furry : public Enemy, public Sprite, public Motion, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Furry(QGraphicsObject *parent);
    Furry(qreal posx, qreal posy, int maxHealth, int atk, QGraphicsObject *parent = nullptr);

private:
    void changeDirectionX();
    int directionX;
};

#endif // FURRY_H
