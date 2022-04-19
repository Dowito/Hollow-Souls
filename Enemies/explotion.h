#ifndef EXPLOTION_H
#define EXPLOTION_H

#include "enemy.h"
class Demon;
class Explotion : public Enemy
{
public:
    Explotion(Demon *demon);
    virtual ~Explotion() {};
    virtual void check() override;

private:
    void animation();
    virtual void attack() override;
};

#endif // EXPLOTION_H
