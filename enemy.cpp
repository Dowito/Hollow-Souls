#include "enemy.h"
#include <player.h>
#include <weapon.h>
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
    for (auto enemy : qAsConst(*enemies)) {
        if(enemy->label == "Explotion") {
            qDebug() << "tamaño enemies: "<< enemies->size();
            qDebug() << "chekeando la explotion " << enemy->control;
        }
        enemy->check();
    }
}

void Enemy::collidesWithPlayer()
{
    if(state){
        if (collidesWithItem(player)) {
            if (!player->getInmu()) dealDamage();
        }
    }
}

void Enemy::collidesWithWeapon()
{
    if (!inmu) {
        if (player->getWeapon()->getAttacking()) {
            if (collidesWithItem(player->getWeapon())) {
                inmu = true;
                takeDamage(player->getWeapon()->getAtk());
            }
        }
    }
    else {
        if(!player->getWeapon()->getAttacking()) inmu = false; //con esto me aseguro que solo reciba un golpe por cada ataque que se haga con la espada
    }
}

void Enemy::dealDamage()
{
    player->takeDamage(atk);
}

void Enemy::changeDirection()
{
    return;
}

void Enemy::takeDamage(int damage, short direction)
{
    if (*health - damage < 0) {
        *health = 0;
        state = false;
        //mirar die y check, Talvez Hacer la animacion de muerte en paralelo
    }
    else *health -= damage;
}

void Enemy::die()
{
    if (!state) {
        qDebug() << "muriendo";
        enemies->removeOne(this);
        qDebug() << control << " removida de la lista";
        scene()->removeItem(this);
        qDebug() << control << " removida de la escena";
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

Player *Enemy::getPlayer()
{
    return player;
}

short Enemy::getDirection() const
{
    return direction;
}

bool Enemy::getInmu() const
{
    return inmu;
}
