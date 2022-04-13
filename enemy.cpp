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

void Enemy::CollidesWithBlock()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if(pos().x() < blocks->at(i)->pos().x() + blocks->at(i)->rect().width()) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
                //v.setX(v.x()*(-1));
            }
            else if (pos().x() + boundingRect().width() > blocks->at(i)->pos().x()) {
                setX(blocks->at(i)->x() - boundingRect().width() - 1);
                //v.setX(v.x()*(-1));
            }
        }
    }
}

void Enemy::collidesWithBlockX()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if (vel.x()<0) {
                pos.setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
            }
            else if (vel.x()>0) {
                pos.setX(blocks->at(i)->x() - w - 1);
            }
            directionX *= (-1);
            //v.setX(v.x()*(-1));
            vel.setX(vel.x()*directionX);
        }
    }
}

void Enemy::collidesWithBlockY()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (vel.y() <= 0) { //si colisiona hacia arriba
                pos.setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
            }
            else { //si colisiona hacia abajo
                pos.setY(blocks->at(i)->y() - h -1);
            }
            vel.setY(0);
            vel.setX(speed*directionX);
        }
    }
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


