#include "circularmotion.h"
CircularMotion::CircularMotion()
{

}

CircularMotion::CircularMotion(float radio, unsigned short direction, float angularVel, float angularAcc)
{
    this->radio = radio;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
    //direccion
    if(direction == 0) {//0 abajo
        angularPos = (-1)*qDegreesToRadians(90.0);
    }
    else if(direction == 1) {//1 izquierda
        angularPos = (-1)*qDegreesToRadians(180.0);
    }
    else if(direction == 2){//2 derecha
        angularPos = (-1)*qDegreesToRadians(0.0);
    }
    else if (direction == 3) {//3 arriba
        angularPos = (-1)*qDegreesToRadians(270.0);
    }
    else {
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

void CircularMotion::calculatePos()
{
    calculateAngle();
    r = {radio*qCos(angularPos), radio*qSin(angularPos)}; //Calcula la posicion, c+luego cuando se actualise la Pos en la escena, se haran calculos para que el sprite quede centrado
    //pos = {radio*qCos(angularPos)-w/2, radio*qSin(angularPos)-h/2};
    //setPos(radio*qCos(angularPos)-w/2, radio*qSin(angularPos)-h/2);
    //---------MALO----------------------
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
