#ifndef PORTAL_H
#define PORTAL_H

#include "sprite.h"
#include "QGraphicsPixmapItem"
class Player;
class Portal : public Sprite, public QGraphicsPixmapItem
{
public:
    Portal(qreal posx, qreal posy, qreal posPlayerX, qreal posPlayerY, unsigned int nextWorld);
    virtual ~Portal() {};
    static void setPlayer(Player *player) {Portal::player = player;};

private:
    unsigned int nextWorld;
    QPointF posPlayerNextWorld;
    static Player *player;
};

#endif // PORTAL_H
