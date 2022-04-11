#include "enemy.h"
#include <player.h>
#include <weapon.h>
Enemy::Enemy()
{

}

Enemy::Enemy(QGraphicsObject *parent)
    :QGraphicsObject(parent)
{
    setParent(parent);
}

Enemy::Enemy(qreal posx, qreal posy, int maxHealth, int atk, short direction, bool inmu, bool state, QGraphicsObject *parent)
    :QGraphicsObject(parent)
{
    setPos(posx,posy);
    this->state = state;
    this->inmu = inmu;
    this->direction = direction;
    this->atk = atk;
    *this->maxHealth = maxHealth;
    *health = *this->maxHealth;
    stepsDie = 0;
}

void Enemy::check()
{
    collisionsPlayer();
    collisionsWeapon();
    die();
}

Player *Enemy::getPlayer()
{
    return player;
}

void Enemy::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Enemy::attack()
{
    /*
    if (player->x() + (player->getW()/2) > this->x()) {
        player->setPos(player->x()+3, player->y()-3);
    }
    else {
        player->setPos(player->x()-3, player->y()-3);
    }
    */
    player->takeDamage(atk);
}

void Enemy::collisionsPlayer()
{
    qDebug() << player->pos();
    if(state){
        if(state){
            if (collidesWithItem(player)) {
                if (!player->getInmu()) attack();
            }
        }
    }
}

void Enemy::collisionsWeapon()
{
    if (!inmu) {
        if (!player->getWeapon()->getAttacking()) {
            if (collidesWithItem(player->getWeapon())) {
                inmu = true;
                takeDamage(player->getWeapon()->getAtk());
            }
        }
    }
    else {
        if(player->getWeapon()->getAttacking()) inmu = false;
    }
}

void Enemy::collisionsBlock()
{

}

void Enemy::takeDamage(int damage)
{
    if (*health - damage < 0){
        *health = 0;
        state = false;
        //mirar die y check
    }
    else health -= damage;
}

void Enemy::die()
{
    if (!state) {
        scene()->removeItem(this);
        delete this;
    }

}

void Enemy::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
}


