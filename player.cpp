#include "player.h"
#include <game.h>
#include <block.h>
#include <weapon.h>
#include <healthbar.h>
#include <bow.h>
#include <QDebug>
extern Game *game;
Player::Player(QObject *parent)
    :QObject(parent)
{
    loadSprite(":/new/sprites/sprites/personaje.png");
    setPixmap(frames[0][1]);
    setFlags(ItemIsFocusable);
    setFocus();
    maxHealth = new int;
    health = new int;
    *maxHealth  = 200;
    *health = *maxHealth;
    direction = 1;
    state = false;
    jump = false;
    inmu = false;
    speed = SPEED_PLAYER;
    v = {0,0};
    calculateAcelerationTest();
    blocks = game->blocks;
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left) {
        direction = 1;
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
        direction = 2;
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
            v.setY(VEL_JUMP);
        }
    }
    else if (event->key() == Qt::Key_X){
        weapon->attack();
    }
    else if (event->key() == Qt::Key_V) {
        bow->shoot(pos(), direction);
    }
}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    v.setY(v.y()+(a.y()*periodo));
    r.setY(r.y()+(v.y()*periodo));
    setY(r.y());
    collisionsY();
}

void Player::collisionsX()
{

}

Bow *Player::getBow() const
{
    return bow;
}

void Player::collisionsY()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (v.y() <= 0) { //si colisiona hacia arriba
                r.setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1);
                setY(r.y());
                v.setY(0);
            }
            else { //si colisiona hacia abajo
                if(jump) jump = false;
                r.setY(blocks->at(i)->y() - h -1);
                setY(blocks->at(i)->y() - h -1);
                v.setY(0);
            }
            break;
        }
    }
}

void Player::framesInmu()
{
    static unsigned short stepsInmu = 0;
    stepsInmu++;
    if(stepsInmu >= STEPS_PLAYER_INMU) {
        inmu = false;
        stepsInmu = 0;
    }
}

void Player::takeDamage(int damage)
{
    if(!inmu){
        if (*health - damage < 0) {
            *health = 0;
            healthBar->update();
            state = false;//animacion de muerte
        }
        else {
            *health -= damage;
            healthBar->update();
            inmu = true;
        }
        qDebug() << "current health: " << *health;
    }
}

void Player::setBow(Bow *newBow)
{
    bow = newBow;
}

void Player::setBlocks(QVector<Block *> *newBlocks)
{
    blocks = newBlocks;
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
