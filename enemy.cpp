#include "enemy.h"
#include <player.h>
#include <healthbar.h>
#include <weapon.h>
#include <block.h>
#include <game.h>
#include <QDebug>
extern Game *game;
Enemy::Enemy(QObject *parent)
    :Motion(parent)
{
    state = true;
}

Enemy::Enemy(QString name, float px, float py, QObject *parent)
    :Motion(parent)
{
    loadSprite(":/new/sprites/sprites/hombre_lobo.png");
    state = true;
    inmu = false;
    atk = 20;
    health = 95;
    //cinematica
    speed = 2;
    directionX = -1;
    setPos(px, py);
    setVel(speed*directionX, 0);
    calculateAcelerationTest();
    //exterior
    blocks = game->blocks;
    player = game->player;
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::move()
{
    //changeDirectionX();
    Motion::move();
    collisionsPlayer();
    collisionsWeapon();
}

void Enemy::collisionsPlayer()
{
    if(state){
        if (collidesWithItem(player)) {
            if (!player->getInmu()) attack();
        }
    }
}

void Enemy::collisionsWeapon()
{
    if (!inmu) {
        if (!player->getWeapon()->getUsable()) {
            if (collidesWithItem(player->getWeapon())) {
                inmu = true;
                setVel(2*player->getWeapon()->getDirection(), -3);
                damage(player->getWeapon()->getAtk());
            }
        }
    }
    else {
        if(player->getWeapon()->getUsable()) inmu = false;
    }
}

void Enemy::changeDirectionX()
{
    if(directionX < 0){ //izquierda
        if(scene()->items({x()-2, y()+h+2}).isEmpty()) directionX *= (-1); //solucion momentanea.
    }
    else {
        if(scene()->items({x()+w+2, y()+h+2}).isEmpty()) directionX *= (-1);
    }
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

void Enemy::damage(int damage)
{
    if (health - damage < 0){
        state = false;
        health = 0;
        disconnect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
        //die animation;
        scene()->removeItem(this);
        delete this;
    }
    else health -= damage;
}
