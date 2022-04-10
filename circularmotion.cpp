#include "circularmotion.h"
CircularMotion::CircularMotion()
{

}

CircularMotion::CircularMotion(float posx, float posy, float radio, unsigned short direction, float angularVel, float angularAcc)
{
    periodo = TTT;
    this->radio = radio;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
    //direccion
    if(direction == 0) {//0 abajo
        setOffset(posx + w/2, posy + h/2 + radio );
        angularPos = (-1)*qDegreesToRadians(90.0);
        setPos(-w/2, h/2 + radio);
    }
    else if(direction == 1) {//1 izquierda
        setOffset(posx + w/2 + radio, posy + h/2);
        angularPos = (-1)*qDegreesToRadians(180.0);
        setPos(-w/2-radio, -h/2);
    }
    else if(direction == 2){//2 derecha
        setOffset(posx + w/2 - radio, posy + h/2);
        angularPos = (-1)*qDegreesToRadians(0.0);
        setPos(radio - w/2, -h/2);
    }
    else if (direction == 3) { //arriba
        setOffset(posx + w/2, posy + h/2 - radio);
        angularPos = (-1)*qDegreesToRadians(270.0);
        setPos(- w/2, -h/2 + radio);
    }
    else {
        setPos(posx, posy);
        this->angularVel = 0;
        this->angularAcc = 0;
        this->radio = 0;
    }
}

/*
CircularMotion::CircularMotion(float posx, float posy, float radio, float angularPos, float angularVel, float angularAcc)
{
    periodo = TTT;
    this->radio = radio;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
    this->angularPos = -angularPos;
    setPos(posx,posy);
    setVel(0,0);
    setAce({0,0});
}
*/

void CircularMotion::move()
{
    calculateAngle();
    setPos(radio*qCos(angularPos)-w/2, radio*qSin(angularPos)-h/2);
    /*
    calculateAceleration();
    v = v + a*periodo;
    setPos(pos() + (v*periodo).toPointF());
    v = radio*angularVel*uniTangential;
    */
}

void CircularMotion::calculateAngle()
{
    angularVel = angularVel + angularAcc*periodo;
    angularPos = angularPos + angularVel*periodo;
}

void CircularMotion::calculateAceleration()
{
    calculateAccNormal();
    calculateAccTangential();
    a = accTangential + accNormal;
}

void CircularMotion::calculateAccNormal()
{
    uniNormal.setX((-1)*qCos(angularPos));
    uniNormal.setY((-1)*qSin(angularPos));
    accNormal = (radio*qPow(angularVel, 2))*uniNormal;
}

void CircularMotion::calculateAccTangential()
{
    uniTangential.setX((-1)*qSin(angularPos));
    uniTangential.setY(qCos(angularPos));
    accTangential = radio*angularAcc*uniTangential;
}
