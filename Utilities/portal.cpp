#include "portal.h"
#include "player.h"
#include "game.h"
#include "QDebug"
extern Game *game;
Portal::Portal(qreal posx, qreal posy, qreal posPlayerX, qreal posPlayerY, unsigned int nextWorld)
{
    loadSprite(":/new/sprites/sprites/portal.png",48,48,1,1);
    setPixmap(frames[0][0]);
    setPos(posx, posy);
    this->nextWorld = nextWorld;
    posPlayerNextWorld.setX(posPlayerX);
    posPlayerNextWorld.setY(posPlayerY);
    portals->push_back(this);
}

void Portal::update()
{
    for (auto portal : qAsConst(*portals)) {
        portal->collidesWithPlayer();
    }
}

void Portal::collidesWithPlayer()
{
    if (collidesWithItem(player)) {
        game->loadNextWorld(this);
    }
}

void Portal::setPortals(QVector<Portal *> *newPortals)
{
    portals = newPortals;
}

QPointF Portal::getPosPlayerNextWorld() const
{
    return posPlayerNextWorld;
}

unsigned int Portal::getNextWorld() const
{
    return nextWorld;
}
