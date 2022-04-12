#include "motion.h"
#include <macros.h>
Motion::Motion()
{
    a.setY(GRAVEDAD);
    periodo = TTT;
}

Motion::Motion(QPointF pos, QPointF vel, QPointF acc)
{
    this->r = pos;
    this->v = vel;
    this->a = acc;
}

Motion::Motion(qreal posx, qreal posy, qreal velx, qreal vely, qreal accx, qreal accy)
{
    r = {posx,posy};
    v = {velx,vely};
    a = {accx,accy};
}

void Motion::move()
{
    //v = v+(a*periodo); //v = v+(a*TTT);
    //r = r+(v*periodo);
    //setPos(pos() + v.toPointF()); //v = v+(a*TTT);
    //setY(y() + vel.y());
    //collisionsY();
    //setX(x() + vel.x());
    //collisionsX();
}

void Motion::collisions()
{
    /*
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if(pos().x() < blocks->at(i)->pos().x() + blocks->at(i)->rect().width()) {
                setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
                v.setX(v.x()*(-1));
            }
            else if (pos().x() + boundingRect().width() > blocks->at(i)->pos().x()) {
                setX(blocks->at(i)->x() - boundingRect().width() - 1);
                v.setX(v.x()*(-1));
            }
        }
    }
    */
}

void Motion::collisionsX()
{
    /*
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))) {
            if (vel.x()<0) {
                pos.setX(blocks->at(i)->x() + blocks->at(i)->rect().width() + 1);
            }
            else if (vel.x()>0) {
                pos.setX(blocks->at(i)->x() - w - 1);
            }
            directionX *= (-1);
            //v.setX(v.x()*(-1));
            vel.setX(vel.x()*directionX);
        }
    }
    */
}

void Motion::collisionsY()
{
    /*
    for (int i = 0; i < blocks->size(); i++) {
        if(collidesWithItem(blocks->at(i))){
            if (vel.y() <= 0) { //si colisiona hacia arriba
                pos.setY(blocks->at(i)->y() + blocks->at(i)->rect().height() + 1 );
            }
            else { //si colisiona hacia abajo
                pos.setY(blocks->at(i)->y() - h -1);
            }
            vel.setY(0);
            vel.setX(speed*directionX);
        }
    }
    */
}

void Motion::calculateAcelerationTest()
{
    a.setY(*gravityTest);
}

short Motion::getDirectionX() const
{
    return directionX;
}

void Motion::setPeriodo(qreal newPeriodo)
{
    periodo = newPeriodo;
}

void Motion::setAce(const QPointF &newA)
{
    a = newA;
}

void Motion::setVel(const QPointF &newV)
{
    v = newV;
}

void Motion::setVel(qreal vx, qreal vy)
{
    v = {vx, vy};
}
