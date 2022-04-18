#include "spike.h"
#include "player.h"
Spike::Spike(qreal posx, qreal posy, qreal spawnx, qreal spawny, int tMaxHealth, int atk, short direction, bool inmu, bool state, QGraphicsObject *parent)
    :Enemy(posx, posy, tMaxHealth, atk, direction, inmu, state, parent)
{
    loadSprite(":/new/sprites/sprites/spike.png", 150, 50, 1, 1);
    setPixmap(frames[0][0]);
    spawnPos = {spawnx, spawny};
}

void Spike::check()
{
    collidesWithPlayer();
}

void Spike::dealDamage()
{
    Enemy::dealDamage();
    player->setVel(0,0);
    player->setRPos(spawnPos);
    player->setPos(spawnPos);
}

void Spike::attack()
{
    return;
}
