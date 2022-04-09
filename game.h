#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <QVector>
class QTimer;
class Block;
class Player;
class Game : public QGraphicsView
{

public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();

    Player *player;
    QTimer *timer;
    QVector<Block*> *blocks;

private:
    void generateCol(int num, int mx, int my);
    void generateFil(int num, int mx, int my);
    void generateSandBox();
    void generateGrid();
};

#endif // GAME_H
