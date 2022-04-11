#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsObject>
#include <QGraphicsScene>
#include <qdebug.h>
class Player;
class Block;
class HealthBar;
class Enemy : public QGraphicsObject
{
    Q_OBJECT
public:
    Enemy();
    explicit Enemy(QGraphicsObject *parent = nullptr);
    /*!
     * \brief Enemy constructor que inicia pos, state, maxHealth, health, atk, stepsDie, inmu , direction y state.
     * para generalizar la creacion de enemigos.
     * \param posx
     * \param posy
     * \param healthMax
     * \param atk
     * \param parent
     */
    Enemy(qreal posx, qreal posy, int maxHealth, int atk, short direction = 0, bool inmu = false, bool state = true, QGraphicsObject *parent = nullptr);
    void check();

    static Player *getPlayer();
    static void setPlayer(Player *newPlayer);   
    static void setBlocks(QVector<Block *> *newBlocks);

protected:
    virtual void collisionsPlayer(); //colisionara mientras este vido
    virtual void collisionsWeapon(); //colisionara mientras no sea inmune, y la duracion dele stado dependera del tiempo de ataque del armar, asi solo podra recibir un hit por cada ataque del arma
    virtual void collisionsBlock(); //para bichos en movimiento
    virtual void attack();
    void takeDamage(int damage);
    void die();
    bool state; //vivo o muerto
    bool inmu; //si es inmune al daño
    unsigned int stepsDie;
    int atk;
    int *health;
    int *maxHealth;
    short direction; //direction donde mira el enemigo. 0=abajo, 1=izquierda, 2=derecha, 3=arriba
    HealthBar *healthbar;
    static Player *player;
    static QList<Enemy*> *enemies;
    static QVector<Block*> *blocks;
};

#endif // ENEMY_H
