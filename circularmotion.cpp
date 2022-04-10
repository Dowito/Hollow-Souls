#include "circularmotion.h"
#include <qdebug.h>
CircularMotion::CircularMotion()
{

}

CircularMotion::CircularMotion(float posx, float posy, float radio, float angularPos, float angularVel, float angularAcc, float speedIni)
{
    setSprite(":/new/sprites/sprites/demonio.png");
    setSize(48,48);
    setFrame(1);
    setPos(144,0);
    setVel(0,0);
    setAce({0,0});
    periodo = TTT;
    this->radio = radio;
    this->angularAcc = angularAcc;
    this->angularVel = angularVel;
    this->angularPos = angularPos;
    this->speed = speedIni;
}

void CircularMotion::move()
{
    calculateAceleration();
    v = v + a*periodo;
    setPos(pos() + (v*periodo).toPointF());
    qDebug() << pos();
}

void CircularMotion::calculateAceleration()
{
    angularVel = angularVel + angularAcc*periodo;
    angularPos = angularPos + angularVel*periodo;
    calculateAccNormal();
    calculateAccTangential();
    a = accTangential + accNormal;
}

void CircularMotion::calculateAccTangential()
{
    uniTangential.setX((-1)*qSin(angularPos));
    uniTangential.setY(qCos(angularPos));
    accTangential = radio*angularAcc*uniTangential;
}

void CircularMotion::calculateAccNormal()
{
    uniNormal.setX((-1)*qCos(angularPos));
    uniNormal.setY((-1)*qSin(angularPos));
    accNormal = radio*angularVel*uniNormal;
}
