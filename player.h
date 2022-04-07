#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <QKeyEvent>
class Player : public Motion
{
    Q_OBJECT
public:
    Player();

private slots:
    virtual void move();

private:
    bool air;
    void keyPressEvent(QKeyEvent *event);
};

#endif // PLAYER_H
