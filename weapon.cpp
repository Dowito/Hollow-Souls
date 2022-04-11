#include "weapon.h"
#include <game.h>
#include <QTransform>
#include <macros.h>
#include <player.h>
#include <QDebug>
extern Game *game;
Weapon::Weapon(Player *owner, QObject *parent)
    :Sprite(parent)
{
    loadSprite(":/new/sprites/sprites/sword.png", 96*2, 96, 5, 5);
    atk = WEAPON_ATK;
    steps = 0;
    attacking = false;
    this->owner = owner;
}

void Weapon::attack()
{
    if(!attacking){
        direction = owner->getDirectionX();
        setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
        setPixmap(frames[0][4]);
        owner->scene()->addItem(this);
        attacking = true;
    }
}

void Weapon::animation()
{
    setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
    if(steps == STEPS_WEAPON_ANIMATION){
        attacking = false;
        steps = 0;
        scene()->removeItem(this);
    }else steps++;
}

short Weapon::getDirection() const
{
    return direction;
}

unsigned short Weapon::getAtk() const
{
    return atk;
}

bool Weapon::getAttacking() const
{
    return attacking;
}
