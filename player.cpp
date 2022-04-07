#include "player.h"
#include <game.h>
#include <block.h>
#include <weapon.h>
#include <healthbar.h>
#include <QDebug>
extern Game *game;
extern float *gravityTest;
Player::Player()
{
    blocks = game->blocks;
    setSprite(":/new/sprites/sprites/personaje.png");
    setSize(48, 48);
    setFrame(2,2);
    setFlags(ItemIsFocusable);
    setFocus();
    jump = false;
    a = {0, 0};
    v = {0,0};
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    calculateAcelerationTest();
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
                a.setY(a.y() - a.y()); //Accion reaccion
            }
            break;
        }
    }
}

void Player::calculateAcelerationTest()
{
    a.setY(*gravityTest);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        setFrame(1,1);
        setX(x()-10);
        for (int i = 0; i < blocks->size(); i++) {
            if(collidesWithItem(blocks->at(i))){
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width());
                break;
            }
        }
    }
    else if (event->key() == Qt::Key_Right) {
        setFrame(1,2);
        setX(x()+10);
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

HealthBar *Player::getHealth() const
{
    return health;
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
