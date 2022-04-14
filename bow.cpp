#include "bow.h"
#include <arrow.h>
#include <player.h>
#include <QGraphicsScene>
#include <QtMath>

Bow::Bow() //arco por defecto para el jugador.
{
    pot = 30.0;
    angle = 30.0;
    atk = 20;
}

Bow::Bow(int atk, qreal pot, qreal angle)
{
    this->pot = pot;
    this->angle = angle;
    this->atk = atk;
}

void Bow::shoot(QPointF posOwner)
{
    calculateVelDir();
    scene()->addItem(new Arrow(posOwner.x(), posOwner.y(), pot*velDir.x(), pot*velDir.y(), atk));
}

void Bow::calculateVelDir()
{
    velDir.setX(qCos(qDegreesToRadians(angle)));
    velDir.setY(qSin(qDegreesToRadians(angle)));
}
