#ifndef WORLD_H
#define WORLD_H

#include <QGraphicsScene>
class Game;
class Block;
class Enemy;
class World : public QGraphicsScene
{
public:
    World(Game *game) { this->game = game;};
    void loadWorld(unsigned short label, QPointF posPlayer);
    void initPlayer();
    void addToWorld(Block *block);

private:
    void clearWorld();
    void updatePosPlayer(QPointF pos);
    void fillSpikes(QVector<Enemy*> &vecEnemies, unsigned int num, qreal posx, qreal posy, qreal posPlayerX, qreal posPlayerY);
    Game *game;
};

#endif // WORLD_H
