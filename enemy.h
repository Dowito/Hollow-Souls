#ifndef ENEMY_H
#define ENEMY_H

#include <motion.h>
class Enemy : public Motion
{
    Q_OBJECT
public:
    Enemy();

private:
    bool inmu;
    int speed;

};

#endif // ENEMY_H
