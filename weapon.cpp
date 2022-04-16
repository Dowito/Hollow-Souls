#include "weapon.h"
#include <game.h>
#include <QTransform>
#include <macros.h>
#include <player.h>
#include <QDebug>
extern Game *game;
Weapon::Weapon(Player *owner, QObject *parent)
    :QObject(parent)
{
    loadSprite(":/new/sprites/sprites/sword - right.png", ":/new/sprites/sprites/sword - left.png", 96*2, 96, 5, 5);
    atk = WEAPON_ATK;
    steps = 0;
    attacking = false;
    this->owner = owner;
}

void Weapon::attack()
{
    if(!attacking){
        direction = owner->getDirection();
        setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
        setPixmap(frames[direction-1][0]);
        owner->scene()->addItem(this);
        attacking = true;
    }
}

void Weapon::animation()
{
    static unsigned short i = 0;
    (direction == 2) ? setPos(owner->x()-10*GAME_SCALE, owner->y()-30*GAME_SCALE) : setPos(owner->x()-135*GAME_SCALE, owner->y()-30*GAME_SCALE);
    if(steps >= 32){
        attacking = false;
        steps = 0;
        i = 0;
        scene()->removeItem(this);
    }
    else if(steps%8 == 0) {
        qDebug() << i;
        setPixmap(frames[direction-1][i]);
        i += 1;
        steps++;
    }
    else steps++;
}

short Weapon::getDirection() const
{
    return direction;
}

void Weapon::loadSprite(QString nameR, QString nameL, unsigned int w, unsigned int h, unsigned short fil, unsigned short col)
{
    Sprite::loadSprite(nameR, w, h, fil, col);
    Sprite::loadSprite(nameL, w, h, fil, col);
    QVector<QPixmap> imBuffer;
    QVector<QVector<QPixmap>> framesBuffer;
    //frames izquierda
    imBuffer.push_back(frames[0+5][1]);
    imBuffer.push_back(frames[0+5][0]);
    imBuffer.push_back(frames[1+5][4]);
    imBuffer.push_back(frames[1+5][3]);
    framesBuffer.push_back(imBuffer);
    //frames derecha
    imBuffer.clear();
    imBuffer.push_back(frames[0][3]);
    imBuffer.push_back(frames[0][4]);
    imBuffer.push_back(frames[1][0]);
    imBuffer.push_back(frames[1][1]);
    framesBuffer.push_back(imBuffer);
    frames.clear();
    frames = framesBuffer;
}

unsigned short Weapon::getAtk() const
{
    return atk;
}

bool Weapon::getAttacking() const
{
    return attacking;
}
