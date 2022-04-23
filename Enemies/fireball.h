#ifndef FIREBALL_H
#define FIREBALL_H

#include "explotion.h"
#include "motion.h"
class Audhulma;
class FireBall : public Explotion, public Motion
{
public:
    FireBall(Audhulma *audhulma);
    virtual ~FireBall() {};

    // Motion interface
public:
    virtual void check() override;

private:
    unsigned int pot;
};

#endif // FIREBALL_H
