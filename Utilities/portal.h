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
    static void update();

    static void setPlayer(Player *player) {Portal::player = player;};
    unsigned int getNextWorld() const;
    QPointF getPosPlayerNextWorld() const;
    static void setPortals(QVector<Portal *> *newPortals);

private:
    void collidesWithPlayer();
    unsigned int nextWorld;
    QPointF posPlayerNextWorld;
    static Player *player;
    static QVector<Portal*> *portals;
};

#endif // PORTAL_H
