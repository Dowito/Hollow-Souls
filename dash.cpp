#include "dash.h"
#include <player.h>
#include <motion.h>
Dash::Dash()
{
    usable = true;
    activated = false;
    pot = 40;
    steps = 0;
}

void Dash::use()
{
    setPos(player->pos());
    setVisible(true);
    usable = false;
    activated = true;
    player->setAce(0.0,0.0);
    player->setVel(pot,0);
    player->clearFocus();
}

void Dash::animation()
{
    if (steps >= 40) {
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
    player->setFocus();
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
