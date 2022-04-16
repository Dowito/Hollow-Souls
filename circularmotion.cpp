#include "circularmotion.h"
CircularMotion::CircularMotion()
{

}

CircularMotion::CircularMotion(float radio, float angularVel, float angularAcc)
{
    this->radio = radio;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
}

/*
CircularMotion::CircularMotion(float radio, float angularPos, float angularVel, float angularAcc)
{
    this->radio = radio;
    this->angularPos = -angularPos;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
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
