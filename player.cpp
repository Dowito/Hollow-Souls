#include "player.h"
#include <game.h>
#include <block.h>
#include <weapon.h>
#include <healthbar.h>
#include <QDebug>
extern Game *game;
Player::Player()
{
    blocks = game->blocks;
    setSprite(":/new/sprites/sprites/personaje.png");
    setSize(48, 48);
    setFrame(2,2);
    setFlags(ItemIsFocusable);
    setFocus();
    jump = false;
    inmu = false;
    speed = SPEED_PLAYER;
    v = {0,0};
    calculateAcelerationTest();
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        directionX = -1;
        setFrame(1,1);
        setX(x() - speed);
        for (int i = 0; i < blocks->size(); i++) {
            if(collidesWithItem(blocks->at(i))){
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width());
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Right) {
        directionX = 1;
        setFrame(1,2);
        setX(x() + speed);
        for (int i = 0; i < blocks->size(); i++) {
            if(collidesWithItem(blocks->at(i))){
                setX(blocks->at(i)->x() - boundingRect().width());
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_C) {
        if(!jump){
            jump = true;
            v.setY(VEL_JUMP);
        }
    }
    else if (event->key() == Qt::Key_X){
        weapon->attack();
    }
}

Weapon *Player::getWeapon() const
{
    return weapon;
}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    v.setY(v.y()+(a.y()*periodo));
    setY(y()+(v.y()*periodo));
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (v.y() <= 0) { //si colisiona hacia arriba
                setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
                v.setY(0);
            }
            else { //si colisiona hacia abajo
                if(jump) jump = false;
                setY(blocks->at(i)->y() - h -1);
                v.setY(0);
                //a.setY(a.y() - a.y()); //Accion reaccion
            }
            break;
        }
    }
}

HealthBar *Player::getHealth() const
{
    return health;
}

void Player::takeDamage(int damage)
{

}

void Player::setHealth(HealthBar *newHealth)
{
    health = newHealth;
}

void Player::setWeapon(Weapon *newWeapon)
{
    weapon = newWeapon;
}

bool Player::getAir() const
{
    return jump;
}

void Player::setAir(bool newAir)
{
    jump = newAir;
}
