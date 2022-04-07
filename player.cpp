#include "player.h"
#include <game.h>
#include <block.h>
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
    a = {0,GRAVEDAD};
    v = {0,0};
    connect(game->timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Player::move() //solo tendra simulacion fisica su movimiento en Y
{
    static unsigned int control = 0;
    static int aceleration = 1;
    a.setY(aceleration);
    v.setY(v.y()+(a.y()*periodo));
    setY(y()+(v.y()*periodo));
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (v.y() <= 0) { //si colisiona hacia arriba
                setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
                v.setY(0);
                qDebug() << "Colisiono " << control;
            }
            else { //si colisiona hacia abajo
                setY(blocks->at(i)->y() - h -1);
                v.setY(0);
                a.setY(a.y() - a.y()); //Accion reaccion
                qDebug() << "Colisiono " << control;
            }
            control++;
            break;
        }
    }
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
    else if (event->key() == Qt::Key_X) {
        v.setY(-10);
    }
}

bool Player::getAir() const
{
    return air;
}

void Player::setAir(bool newAir)
{
    air = newAir;
}
