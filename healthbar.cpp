#include "healthbar.h"
#include <QBrush>
#include <player.h>
#include <QGraphicsScene>
HealthBar::HealthBar(Player *owner, QObject *parent)
    : QObject{parent}
{
    maxHealth = owner->getMaxHealth();
    health = owner->getHealth();
    //pintando la barra vacia
    setRect(0,0,200,30);
    setBrush(QBrush(QColor(Qt::lightGray)));
    //Pintando la barra roja
    updateHealth = new QGraphicsRectItem;
    updateHealth->setRect(0, 0, rect().width(), rect().height());
    updateHealth->setBrush(QBrush(QColor(Qt::red)));
    //posiciones
    setPos(20,20);
    updateHealth->setPos(pos());
    update();
}

unsigned short HealthBar::healthPercent()
{
    return ((*health)*100)/(*maxHealth);
}

QGraphicsRectItem *HealthBar::getUpdateHealth() const
{
    return updateHealth;
}

void HealthBar::update()
{
    updateHealth->setRect(0, 0, healthPercent()*2, rect().height());
}
