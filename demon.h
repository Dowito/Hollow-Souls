#ifndef DEMON_H
#define DEMON_H

#include <enemy.h>
class Demon : public Enemy
{
    Q_OBJECT
public:
    Demon() {};
    Demon(qreal posx, qreal posy, short direction = 0);
    virtual ~Demon() {};

    virtual void check() override;

private:
    virtual void attack() override;
};

#endif // DEMON_H
