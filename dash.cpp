#include "dash.h"
#include <player.h>
#include <motion.h>
#include <weapon.h>
#include <QDebug>
Dash::Dash()
{
    usable = true;
    activated = false;
    pot = 115;
    steps = 0;
}

void Dash::use()
{
    setPos(player->pos());
    setVisible(true);
    usable = false;
    activated = true;
    player->setAce(0.0,0.0);
    (player->getDirection()==1) ? player->setVel((-1)*pot,0) : player->setVel(pot,0);
    if(!player->getWeapon()->getAttacking()) player->setInmu(true);
    player->setRPos(player->pos());
}

void Dash::effect()
{
    player->moveX();
    if (steps >= 20) {
        finish();
        //ver Player::collidesWithBlockY donde se cambia el estado a true
    }
    else {
        setPos(player->pos());
        steps++;
    }
}

void Dash::finish()
{
    steps = 0;
    setVisible(false);
    player->setAce(0.0, GRAVEDAD);
    player->setVel(0,0);
    player->setInmu(false);
    //usable = true;//se vuelve a activar solo cuando hace contacto con el piso
    activated = false;
}

Player *Dash::getPlayer() const
{
    return player;
}

bool Dash::getActivated() const
{
    return activated;
}

void Dash::setActivated(bool newActivated)
{
    activated = newActivated;
}

bool Dash::getUsable() const
{
    return usable;
}

void Dash::setUsable(bool newUsable)
{
    usable = newUsable;
}

void Dash::setPlayer(Player *newPlayer)
{
    player = newPlayer;
}
