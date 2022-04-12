#include "enemy.h"
#include <player.h>
#include <weapon.h>
#include <block.h>
Enemy::Enemy(QGraphicsObject *parent)
    :QGraphicsPixmapItem(parent)
{
    loadSprite(":/new/sprites/sprites/bomba.png");
    setPos(0,0);
    state = true;
    inmu = false;
    direction = 0;
    atk = 10;
    *maxHealth = 100;
    *health = *maxHealth;
    stepsDie = 0;
    enemies->push_back(this);
}

Enemy::Enemy(qreal posx, qreal posy, int tMaxHealth, int atk, short direction, bool inmu, bool state, QGraphicsObject *parent)
    :QGraphicsPixmapItem(parent)
{
    maxHealth = new int;
    health = new int;
    setPos(posx,posy);
    *maxHealth = tMaxHealth;
    *health = *maxHealth;
    this->atk = atk;
    this->direction = direction;
    if((this->direction<0) | (this->direction>3)) this->direction = 0;
    this->inmu = inmu;
    this->state = state;
    stepsDie = 0;
    enemies->push_back(this);
}

void Enemy::update()
{
    for (auto caca : *enemies) {
        caca->check();
    }
}

void Enemy::collisionsPlayer()
{
    if(state){
        if (collidesWithItem(player)) {
            if (!player->getInmu()) dealDamage();
        }
    }
}

void Enemy::collisionsWeapon()
{
    if (!inmu) {
        if (player->getWeapon()->getAttacking()) {
            if (collidesWithItem(player->getWeapon())) {
                inmu = true;
                qDebug() << *health;
                qDebug() << inmu;
                takeDamage(player->getWeapon()->getAtk());
            }
        }
    }
    else {
        if(!player->getWeapon()->getAttacking()) inmu = false; //con esto me aseguro que solo reciba un golpe por cada ataque que se haga con la espada
    }
}

void Enemy::collisionsBlock()
{
    return;
}

void Enemy::dealDamage()
{
    player->takeDamage(atk);
}

Player *Enemy::getPlayer()
{
    return player;
}

void Enemy::takeDamage(int damage)
{
    if (*health - damage < 0){
        *health = 0;
        state = false;
        //mirar die y check, Talvez Hacer la animacion de muerte en paralelo
    }
    else *health -= damage;
}

void Enemy::die()
{
    if (!state) {
        enemies->removeOne(this);
        scene()->removeItem(this);
        delete this;
    }

}

void Enemy::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}

void Enemy::setEnemies(QList<Enemy *> *newEnemies)
{
    enemies = newEnemies;
}

void Enemy::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
}


