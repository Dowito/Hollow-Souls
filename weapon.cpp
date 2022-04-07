#include "weapon.h"
#include <game.h>
#include <QTransform>
#include <macros.h>
#include <player.h>
extern Game *game;
Weapon::Weapon(Player *owner, QObject *parent)
    :Sprite(parent)
{
    //slash special sword5
    //bblow phisical
    setSprite(":/new/sprites/sprites/sword.png");
    setSize(96*2,96);
    int **matriz = new int *[2];
    for (int i = 0; i<2; i++) {
        matriz[i] = new int[2];
    }
    matriz[0][0] = 0;
    matriz[1][0] = 1;
    matriz[0][1] = -1;
    matriz[1][1] = 0;
    setTransform(QTransform());
    atk = WEAPON_ATK;
    steps = 0;
    usable = true;
    this->owner = owner;
    this->timer = game->timer;
}

void Weapon::attack()
{
    if(usable){
        usable = false;
        setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
        setFrame(4,0);
        owner->scene()->addItem(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(animation()));
    }
}

void Weapon::animation()
{
    setPos(owner->x()-20*GAME_SCALE, owner->y()-30*GAME_SCALE);
    if(steps == STEPS_WEAPON_ANIMATION){
        disconnect(timer, SIGNAL(timeout()), this, SLOT(animation()));
        owner->scene()->removeItem(this);
        usable = true;
        steps = 0;
    }else steps++;
}

bool Weapon::getUsable() const
{
    return usable;
}
