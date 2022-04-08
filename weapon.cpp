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
    //slash special sword5
    //bblow phisical
    setSprite(":/new/sprites/sprites/sword.png");
    setSize(96*2,96);
    atk = WEAPON_ATK;
    steps = 0;
    usable = true;
    this->owner = owner;
    this->timer = game->timer;
}

void Weapon::attack()
{
    if(usable){
        setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
        setFrame(4,0);
        usable = false;
        owner->scene()->addItem(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(animation()));
    }
}

void Weapon::animation()
{
    setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
    if(steps == STEPS_WEAPON_ANIMATION){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(animation()));
        usable = true;
        steps = 0;
        scene()->removeItem(this);
    }else steps++;
}

unsigned short Weapon::getAtk() const
{
    return atk;
}

bool Weapon::getUsable() const
{
    return usable;
}
