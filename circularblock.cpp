#include "circularblock.h"

CircularBlock::CircularBlock(qreal posx, qreal posy,
                             unsigned int width,
                             unsigned int height,
                             float radio,
                             unsigned short direction,
                             float angularVel,
                             float angularAcc)
    //:CircularMotion(radio, direction, angularVel, angularAcc)
{
    setRect(0,0,width,height);
    setPos(posx, posy);
    /*
    if(direction == 0) {//0 abajo
        setRect(posx + width/2, posy + height/2 + radio, width, height);
        setPos(-width/2, height/2 + radio);
    }
    else if(direction == 1) {//1 izquierda
        setRect(posx + width/2 + radio, posy + height/2, width, height);
        setPos(-width/2-radio, -height/2);
    }
    else if(direction == 2){//2 derecha
        setRect(posx + width/2 - radio, posy + height/2, width, height);
        setPos(radio - width/2, -height/2);
    }
    else if (direction == 3) { //arriba
        setRect(posx + width/2, posy + height/2 - radio, width, height);
        setPos(- width/2, -height/2 + radio);
    }
    else {
        setRect(0,0,width,height);
        setPos(posx, posy);
        this->angularVel = 0;
        this->angularAcc = 0;
        this->radio = 0;
    }
    */
}
