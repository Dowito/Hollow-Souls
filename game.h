#ifndef GAME_H
#define GAME_H

#include <QWidget>
#include <QGraphicsView>
#include <string>
using namespace std;

class QTimer;
class Block;
class Player;
class Enemy;
class Arrow;
class World;
class Menu;
class GameOver;
class LoadScreen;
class Portal;
class Game : public QGraphicsView
{
    Q_OBJECT
public:
    explicit Game(QWidget *parent = nullptr);
    ~Game();
    string user;
    QTimer *timer;
    Player *player;
    QVector<Block*> *blocks;
    QVector<Portal*> *portals;
    QList<Enemy*> *enemies;
    QList<Arrow*> *arrows;
    //Screens
    World *world;
    GameOver *gameover;
    LoadScreen *loadscreen;
    Menu *menu;

public slots:
    /*!
     * \brief timeWorld Funcion que se conecta a un timer, maneja todo lo relacionado con los procesos que se tienen que hacer en segundo plane
     * y que denpenden de un tiempo. Por ejemplo el movimiento, las colisiones, animaciones de muerte etc.
     */
    void timeWorld();
    void loadNextWorld(Portal *portal);
    void loadNextWorld(unsigned short world, qreal posx, qreal posy);
    void newGame();
    void loadGame();

private:
    void initStaticVar();
};

#endif // GAME_H
