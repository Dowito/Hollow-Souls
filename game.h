#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
class QTimer;
class Block;
class Player;
class Enemy;
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    Player *player;
    QTimer *timer;
    QVector<Block*> *blocks;
    QList<Enemy*> *enemies;

public slots:
    /*!
     * \brief timeWorld Funcion que se conecta a un timer, maneja todo lo relacionado con los procesos que se tienen que hacer en segundo plane
     * y que denpenden de un tiempo. Por ejemplo el movimiento, las colisiones, animaciones de muerte etc.
     */
    void timeWorld();
};

#endif // GAME_H
