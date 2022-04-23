#include "circularblock.h"
#include <QDebug>
CircularBlock::CircularBlock(qreal posx, qreal posy,
                             unsigned int width,
                             unsigned int height,
                             float radio,
                             unsigned short direction,
                             float angularVel,
                             float angularAcc)
    //:CircularMotion(radio, angularVel, angularAcc)
{
    this->radio = radio;
    this->angularAcc = -angularAcc;
    this->angularVel = -angularVel;
    //setRect(0, 0, width, height);
    //setPos(posy, posx);
    //direccion
    //setRect en dos primeros parametros define cual seran el origen del objeto a crear con respecto a las coordenadas de la scena
    if(direction == 0) {//0 abajo
        setRect(posx + width/2, posy + height/2 + radio, width, height);
        angularPos = (-1)*qDegreesToRadians(90.0);
        setPos(-float(width)/2, -float(height)/2 - radio-2);//setPos(-width/2, -height/2 - radio);
        qDebug() << pos();
    }
    else if(direction == 1) {//1 izquierda
        setRect(posx + width/2 + radio, posy + height/2, width, height);
        angularPos = (-1)*qDegreesToRadians(180.0);
        setPos(-float(width)/2-radio, -float(height)/2);
    }
    else if(direction == 2){//2 derecha
        setRect(posx + width/2 - radio, posy + height/2, width, height);
        angularPos = (-1)*qDegreesToRadians(0.0);
        setPos(radio - float(width)/2, -float(height)/2);
    }
    else if (direction == 3) { //3 arriba
        setRect(posx + width/2, posy + height/2 - radio, width, height);
        angularPos = (-1)*qDegreesToRadians(270.0);
        setPos(- float(width)/2, -float(height)/2 + radio);
    }
    else {
        setRect(posx, posy, width, height);
        setPos(posx, posy);
        this->angularVel = 0;
        this->angularAcc = 0;
        this->radio = 0;
    }
}

void CircularBlock::check()
{
    calculatePos();
    setPos(radio*qCos(angularPos)-float(rect().width())/2, radio*qSin(angularPos)-float(rect().height())/2);
}
