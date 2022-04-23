#include "button.h"
#include <QBrush>
#include <QFont>
#include <QGraphicsTextItem>
Button::Button(QString name, QObject *parent)
    : QObject{parent}
{
    setRect(0,0,200,50);
    QBrush brush;
    brush.setStyle(Qt::Dense6Pattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);
    //texto
    text = new QGraphicsTextItem(name,this);
    QFont font("Tahoma",15);
    text->setFont(font);
    int xPos = rect().width()/2 - text->boundingRect().width()/2;
    int yPos = rect().height()/2 - text->boundingRect().height()/2;
    text->setPos(xPos,yPos);
    text->setDefaultTextColor(Qt::white);
    setAcceptHoverEvents(true);
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::magenta);
    setBrush(brush);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QBrush brush;
    brush.setStyle(Qt::Dense6Pattern);
    brush.setColor(Qt::darkMagenta);
    setBrush(brush);
}
