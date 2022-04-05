#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <motion.h>
class QTimer;
class Game : public QGraphicsView
{

public:
    explicit Game(QWidget *parent = nullptr);
    Motion *prueba;
    QTimer *timer;
};

#endif // GAME_H
