#include "player.h"
#include <game.h>
#include <block.h>
#include <weapon.h>
#include <healthbar.h>
#include <QDebug>
extern Game *game;
Player::Player()
{
    jump = false;
    inmu = false;
    maxPlayerHealth  = 200;
    playerHealth = maxPlayerHealth;
    setSprite(":/new/sprites/sprites/personaje.png");
    setSize(48, 48);
    setFrame(2,2);
    setFlags(ItemIsFocusable);
    setFocus();
    speed = SPEED_PLAYER;
    v = {0,0};
    calculateAcelerationTest();
    blocks = game->blocks;
    timer = game->timer;
    connect(timer, SIGNAL(timeout()), this, SLOT(move()));
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

bool Player::getInmu() const
{
    return inmu;
}

void Player::setJump(bool newJump)
{
    jump = newJump;
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

void Player::framesInmu()
{
    static unsigned short stepsInmu;
    stepsInmu++;
    if(stepsInmu >= STEPS_PLAYER_INMU) {
        inmu = false;
        stepsInmu = 0;
        disconnect(timer, SIGNAL(timeout()), this, SLOT(framesInmu()));
    }
}

HealthBar *Player::getHealth() const
{
    return health;
}

void Player::takeDamage(int damage)
{
    if(!inmu){
        if (playerHealth - damage < 0) {
            playerHealth = 0;
            //animacion de muerte
        }
        else {
            playerHealth -= damage;
            inmu = true;
            connect(timer, SIGNAL(timeout()), this, SLOT(framesInmu()));
        }
        qDebug() << "current health: " << playerHealth;
    }
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
