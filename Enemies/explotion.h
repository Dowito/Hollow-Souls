#ifndef EXPLOTION_H
#define EXPLOTION_H

#include "enemy.h"
class Demon;
class Explotion : public Enemy
{
public:
    Explotion(Demon *demon);
    Explotion(qreal posx, qreal posy);
    virtual ~Explotion() {};
    virtual void check() override;

protected:
    unsigned int duration;
    void animation();

private:
    virtual void attack() override;
};

#endif // EXPLOTION_H
