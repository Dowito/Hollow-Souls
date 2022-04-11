#include "player.h"
#include <game.h>
#include <block.h>
#include <weapon.h>
#include <healthbar.h>
#include <QDebug>
extern Game *game;
Player::Player()
{
    loadSprite(":/new/sprites/sprites/personaje.png");
    setFlags(ItemIsFocusable);
    setFocus();
    maxHealth = new int;
    health = new int;
    jump = false;
    inmu = false;
    *maxHealth  = 200;
    *health = *maxHealth;
    speed = SPEED_PLAYER;
    vel = {0,0};
    calculateAcelerationTest();
    blocks = game->blocks;
    timer = game->timer;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        directionX = -1;
        setPixmap(frames[1][1]);
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
        //setFrame(1,2);
        setPixmap(frames[2][1]);
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
            vel.setY(VEL_JUMP);
        }
    }
    else if (event->key() == Qt::Key_X){
        weapon->attack();
    }
}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    vel.setY(vel.y()+(acc.y()*periodo));
    setY(y()+(vel.y()*periodo));
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (vel.y() <= 0) { //si colisiona hacia arriba
                setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
                vel.setY(0);
            }
            else { //si colisiona hacia abajo
                if(jump) jump = false;
                setY(blocks->at(i)->y() - h -1);
                vel.setY(0);
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

void Player::takeDamage(int damage)
{
    if(!inmu){
        if (*health - damage < 0) {
            *health = 0;
            healthBar->update();
            //animacion de muerte
        }
        else {
            inmu = true;
            *health -= damage;
            healthBar->update();
            connect(timer, SIGNAL(timeout()), this, SLOT(framesInmu()));
        }
        qDebug() << "current health: " << *health;
    }
}

int *Player::getHealth() const
{
    return health;
}

void Player::setHealth(int newHealth)
{
    *health = newHealth;
}

int *Player::getMaxHealth() const
{
    return maxHealth;
}

void Player::setMaxHealth(int newMaxHealth)
{
    *maxHealth = newMaxHealth;
}

HealthBar *Player::getHealthBar() const
{
    return healthBar;
}

void Player::setHealthBar(HealthBar *newHealthBar)
{
    healthBar = newHealthBar;
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
