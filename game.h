#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
class Game : public QGraphicsView
{

public:
    explicit Game(QWidget *parent = nullptr);
};

#endif // GAME_H
