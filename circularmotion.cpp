#include "circularmotion.h"
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <qdebug.h>
CircularMotion::CircularMotion()
{

}

CircularMotion::CircularMotion(float posx, float posy, float radio, float angularPos, float angularVel, float angularAcc, float speedIni)
{
    setOffset(144*2,144);
    setSprite(":/new/sprites/sprites/demonio.png");
    setSize(48,48);
    setFrame(1);
    setPos(radio,0);
    setVel(0,-10);
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
    QGraphicsRectItem *path;
    path = new QGraphicsRectItem(offset().x(), offset().y(),10,10);
    path->setPos(pos());
    scene()->addItem(path);
    calculateAngle();
    setPos(radio*qCos(angularPos),radio*qSin(angularPos));
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
