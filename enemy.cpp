#include "enemy.h"
#include <player.h>
#include <healthbar.h>
#include <weapon.h>
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
    state = true;
    inmu = false;
    atk = 20;
    health = 95;
    //sprites
    setSprite(name);
    setSize(48,48);
    setFrame(1);
    //cinematica
    direction = speed/speed;
    speed = -2;
    setPos(px, py);
    setVel(speed, 0);
    calculateAcelerationTest();
    //exterior
    blocks = game->blocks;
    player = game->player;
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::move()
{
    Motion::move();
    collisionsPlayer();
    collisionsWeapon();
}

void Enemy::collisionsPlayer()
{
    if(state){
        if (collidesWithItem(player)) {
            attack();
        }
    }
}

void Enemy::collisionsWeapon()
{
    if (!inmu) {
        if (!player->getWeapon()->getUsable()) {
            if (collidesWithItem(player->getWeapon())) {
                inmu = true;
                damage(player->getWeapon()->getAtk());
            }
        }
    }
    else {
        if(player->getWeapon()->getUsable()) inmu = false;
    }
}


void Enemy::attack()
{
    player->getHealth()->damage(atk);
}

void Enemy::damage(int damage)
{
    qDebug() << "recibe daño";
    if (health - damage < 0){
        state = false;
        health = 0;
        disconnect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
        //die animation;
        scene()->removeItem(this);
    }
    else health -= damage;
}
