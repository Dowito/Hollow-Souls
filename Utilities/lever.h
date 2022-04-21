#ifndef LEVER_H
#define LEVER_H

#include "enemy.h"
class Lever : public Enemy
{
public:
    Lever(qreal posx, qreal posy);
    virtual ~Lever() {};

private:
    void ON();

    // Enemy interface
public:
    void check();

protected:
    void attack();
};

#endif // LEVER_H
