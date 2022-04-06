#include "player.h"
#include <game.h>
#include <QDebug>
extern Game *game;
Player::Player()
{
    setSprite(":/new/sprites/sprites/personaje.png");
    setSize(48, 48);
    setFrame(2,2);
    setFlags(ItemIsFocusable);
    setFocus();
    a = {0,GRAVEDAD};
    v = {0,0};
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
    connect(game->timer, SIGNAL(timeout()), this, SLOT(focuson()));

}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    v.setY(v.y()+(a.y()*periodo)); //v = v+(a*TTT);
    setY(y()+(v.y()*periodo));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        setX(x()-1);
    }
    else if (event->key() == Qt::Key_Right) {
        setX(x()+1);
    }
    else if (event->key() == Qt::Key_X) {
        v.setY(-20);
    }
}
