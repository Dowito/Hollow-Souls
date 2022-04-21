#include "saw.h"

Saw::Saw(qreal posx, qreal posy, unsigned int width, unsigned int height, float radio, unsigned short direction, float angularVel, qreal scale, float angularAcc)
    :Enemy(60),
      CircularMotion(radio, angularVel, angularAcc)

{
    loadSprite(":/new/sprites/sprites/saw.png",50,50,1,1);
    setPixmap(frames[0][0]);
    setScale(scale);
    w *= scale;
    h *= scale;
    qDebug() << "h: " << h/2;
    qDebug() << "w: " << w/2;
    width = w;
    height = h;
    if(direction == 0) {//0 abajo
        setOffset(posx + width/2, posy + height/2 + radio);
        angularPos = (-1)*qDegreesToRadians(90.0);
        setPos(-float(width)/2, -float(height)/2 - radio-2);//setPos(-width/2, -height/2 - radio);
    }
    else if(direction == 1) {//1 izquierda
        setOffset(posx + width/2 + radio, posy + height/2);
        angularPos = (-1)*qDegreesToRadians(180.0);
        setPos(-float(width)/2-radio, -float(height)/2);
    }
    else if(direction == 2){//2 derecha
        setOffset(posx + qreal(w)/2 - radio, posy + qreal(h)/2);
        angularPos = (-1)*qDegreesToRadians(0.0);
        setPos(radio -qreal(w)/2, -qreal(h)/2);
    }
    else if (direction == 3) { //3 arriba
        setOffset(posx + width/2, posy + height/2 - radio);
        angularPos = (-1)*qDegreesToRadians(270.0);
        setPos(- float(width)/2, -float(height)/2 + radio);
    }
    else {
        setOffset(posx, posy);
        setPos(posx, posy);
    }

}

Saw::Saw(qreal oposx, qreal oposy, qreal scale, qreal radio, qreal angularPos, qreal angularVel, qreal angularAcc)
    :Enemy(60),
      CircularMotion(radio, angularVel, angularAcc)
{
    this->angularPos = angularPos;
    loadSprite(":/new/sprites/sprites/saw.png",50,50,1,1);
    frames[0][0] = frames[0][0].scaled(50*scale,50*scale);
    setPixmap(frames[0][0]);
    setOffset(oposx,oposy);
    w *= scale;
    h *= scale;
    setPos(radio*qCos(angularPos)-float(w)/2, radio*qSin(angularPos)-float(h)/2);
}

void Saw::check()
{
    move();
    collidesWithPlayer();
}

void Saw::move()
{
    calculatePos();
    setPos(radio*qCos(angularPos)-float(w)/2, radio*qSin(angularPos)-float(h)/2);
}

void Saw::attack()
{
    return;
}
