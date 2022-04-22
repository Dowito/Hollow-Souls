#include "audhulma.h"
#include "player.h"
#include "bow.h"
#include "fireball.h"
#include "explotion.h"
Audhulma::Audhulma(qreal posx, qreal posy)
    :Enemy(posx,posy,600,60)
{
    loadSprite(":/new/sprites/sprites/boss_dragon.png",120,120,1,3);
    setPixmap(frames[0][1]);
    delay = 0;
    limit = false;
}

void Audhulma::check()
{
    if(state){
        limitPlayer();
        collidesWithPlayer();
        collidesWithWeapon();
        attack();
    }
    else die();
}

void Audhulma::inmulateFloor()
{
    for (unsigned short i = 0; i <= 11; i++) {
        scene()->addItem(new Explotion(14*SB+(i*100),7*SB+50));
        scene()->addItem(new Explotion(13*SB-100-(i*100),7*SB+50));
    }
}

void Audhulma::fireBall()
{
    calculateDirectionPlayer();
    scene()->addItem(new FireBall(this));
}

void Audhulma::calculateDirectionPlayer()
{
    QPointF dist = player->pos() - pos();
    directionPlayer = dist/dist.manhattanLength();
}

void Audhulma::limitPlayer()
{
    if(limit) {
        if(player->pos().x() < 6*SB || player->pos().x()+48 > 21*SB) {
            (player->pos().x() < 6*SB) ? player->setX(6*SB+2) : player->setX(21*SB-50);
        }
    }
    else{
        if(player->pos().x() > 6*SB) limit = true;
    }
}

void Audhulma::attack()
{
    if(delay >= 400){
        if (player->pos().y()<7*SB) {
            fireBall();
        }
        else{
            inmulateFloor();
        }
        delay = 0;
    }
    else delay++;
}

void Audhulma::die()
{
    player->getBow()->setIfEquip(true);
    Enemy::die();
}

QPointF Audhulma::getDirectionPlayer() const
{
    return directionPlayer;
}
