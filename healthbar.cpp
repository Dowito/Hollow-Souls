#include "healthbar.h"
#include <QBrush>
#include <player.h>
#include <QGraphicsScene>
#include <QDebug>
HealthBar::HealthBar(Player *owner, QObject *parent)
    : QObject{parent}
{
    //pintando la barra vacia
    setRect(0,0,200,30);
    setBrush(QBrush(QColor(Qt::lightGray)));
    //Pintando la barra roja
    updateHealth.setRect(0, 0, rect().width(), rect().height());
    updateHealth.setBrush(QBrush(QColor(Qt::red)));
    //posiciones
    setPos(20,20);
    updateHealth.setPos(20,20);
    //inicializando la vida
    maxHealth = 200;
    health = maxHealth;
    update();
    owner->scene()->addItem(this);
    owner->scene()->addItem(&updateHealth);
}

void HealthBar::cure(int cure)
{
    if (health + cure > maxHealth){
        health = maxHealth;
    }
    else health += cure;
    update();
}

void HealthBar::damage(int damage)
{
    if (health - damage < 0) {
        health = 0;
    }
    else health -= damage;
    update();
}

unsigned short HealthBar::healthPercent()
{
    return (health*100)/maxHealth;
}

void HealthBar::update()
{
    updateHealth.setRect(0, 0, healthPercent()*2, rect().height());
}
