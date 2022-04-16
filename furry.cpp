#include "furry.h"
#include <block.h>
#include <player.h>
#include <weapon.h>
Furry::Furry(qreal posx, qreal posy, qreal velx, qreal vely, int maxHealth, int atk)
    :Enemy(posx, posy, maxHealth, atk),
      Motion(posx, posy, velx, vely) //velocidad por defecto en velx = 1;
{
    loadSprite(":/new/sprites/sprites/furro.png");
    setPixmap(frames[this->direction][1]);
    hit = false;
}

void Furry::check()
{
    if(state){ //interactua solo si esta vivo
        move();
        collidesWithWeapon(); //revisa si recibe daño de un arma
        collidesWithPlayer(); //revisa si le hace daño al jugador por contacto
    }
    else die();
}

void Furry::move()
{
    calculatePos();
    setY(r.y());
    collidesWithBlockY();
    setX(r.x());
    collidesWithBlockX();
    calculateDirection();
}

void Furry::CollidesWithBlock()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if(pos().x() < blocks->at(i)->pos().x() + blocks->at(i)->rect().width()) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
                //v.setX(v.x()*(-1));
            }
            else if (pos().x() + boundingRect().width() > blocks->at(i)->pos().x()) {
                setX(blocks->at(i)->x() - boundingRect().width() - 1);
                //v.setX(v.x()*(-1));
            }
        }
    }
}

void Furry::collidesWithBlockX()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if (v.x()<0) { //Colision hacia la izquierda
                r.setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
            }
            else if (v.x()>0) { //colision hacia la derecha
                r.setX(blocks->at(i)->x() - w - 1);
            }
            v.setX(v.x()*(-1));
            setX(r.x());
            //directionX *= (-1);
            //v.setX(v.x()*directionX);
        }
    }
}

void Furry::collidesWithBlockY()
{
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (v.y() <= 0) { //si colisiona hacia arriba
                r.setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
            }
            else { //si colisiona hacia abajo
                r.setY(blocks->at(i)->y() - h - 1);
                if(hit) changeDirection();
            }
            v.setY(0);
            setY(r.y());
        }
    }
}

void Furry::calculateDirection()
{
    if(v.x() < 0) direction = 1; //izquierda
    else direction = 2; //derecha
}

void Furry::attack()
{
    return;
}

void Furry::changeDirection()
{
    (direction == 1) ? direction = 2 : direction = 1;
    v.setX((-1)*v.x());
    hit = false;
}

void Furry::takeDamage(int damage, short direction)
{
    Enemy::takeDamage(damage);
    if(state){
        //Sistemas de direcciones y feedBack.
        v.setY(-25);
        if(this->direction != direction){
            this->direction = direction;
            v.setX((-1)*v.x());
            hit = true;
        }
    }
}

/*
void Enemy::tryFloor()
{
    if(directionX < 0){ //izquierda
        if(scene()->items({x()-2, y()+h+2}).isEmpty()) directionX *= (-1); //solucion momentanea.
    }
    else {
        if(scene()->items({x()+w+2, y()+h+2}).isEmpty()) directionX *= (-1);
    }
}
*/
