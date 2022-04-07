#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
class Player;
class Motion;
class HealthBar : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    explicit HealthBar(Player *owner, QObject *parent = nullptr);
    void cure(int cure);
    void damage(int damage);

private:
    unsigned short healthPercent();
    void update();

    int health;
    int maxHealth;
    QGraphicsRectItem updateHealth;
};

#endif // HEALTHBAR_H
