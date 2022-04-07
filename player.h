#ifndef PLAYER_H
#define PLAYER_H

#include <motion.h>
#include <QKeyEvent>
#include <QVector>
class Block;
class Player : public Motion
{
    Q_OBJECT
public:
    Player();

    bool getAir() const;
    void setAir(bool newAir);

private slots:
    virtual void move();

private:
    void keyPressEvent(QKeyEvent *event);
    bool air;
    QVector<Block*> *blocks;
};

#endif // PLAYER_H
