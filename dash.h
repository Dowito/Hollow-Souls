#ifndef DASH_H
#define DASH_H

#include <sprite.h>
#include <QGraphicsPixmapItem>
class Player;
class Dash : public Sprite, public QGraphicsPixmapItem
{
public:
    Dash();
    void use();
    void animation();
    static void setPlayer(Player *newPlayer);

    bool getActivated() const;
    void setActivated(bool newActivated);
    bool getUsable() const;
    void setUsable(bool newUsable);

private:
    void finish();
    bool activated;
    bool usable;
    double pot;
    unsigned int steps;
    static Player *player;
};

#endif // DASH_H
