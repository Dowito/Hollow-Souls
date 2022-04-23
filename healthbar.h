#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QObject>
#include <QGraphicsRectItem>
#include <QGraphicsTextItem>
#include <game.h>
class Player;
class Motion;
class Game;
class HealthBar : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    HealthBar(Game *parent) {setParent(parent);};
    explicit HealthBar(Player *owner, QObject *parent = nullptr);
    void update();

    void posUpdateHealth();
    QGraphicsRectItem *getUpdateHealth() const;

private:
    unsigned short healthPercent();
    int *health;
    int *maxHealth;
    QGraphicsRectItem *updateHealth;
    Player *player;
};

#endif // HEALTHBAR_H
