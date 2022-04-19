#include "portal.h"

Portal::Portal(qreal posx, qreal posy, qreal posPlayerX, qreal posPlayerY, unsigned int nextWorld)
{
    loadSprite(":/new/sprites/sprites/portal.png",48,48,1,1);
    setPixmap(frames[0][0]);
    setPos(posx, posy);
    this->nextWorld = nextWorld;
    posPlayerNextWorld.setX(posPlayerX);
    posPlayerNextWorld.setY(posPlayerY);
}
