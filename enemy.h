#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <sprite.h>
#include <qdebug.h>
class Player;
class Block;
class HealthBar;
class Enemy : public QObject, public QGraphicsPixmapItem, public Sprite
{
    Q_OBJECT
public:
    explicit Enemy(QGraphicsObject *parent = nullptr);
    Enemy(int atk, QGraphicsObject *parent = nullptr);
    /*!
     * \brief Enemy constructor que inicia pos, state, maxHealth, health, atk, stepsDie, inmu , direction y state.
     * para generalizar la creacion de enemigos.
     * \param posx
     * \param posy
     * \param healthMax
     * \param atk
     * \param parent
     */
    Enemy(qreal posx, qreal posy,
          int tMaxHealth,
          int atk,
          short direction = 0,
          bool inmu = false,
          bool state = true,
          QGraphicsObject *parent = nullptr);
    virtual ~Enemy() {};

    static void update();
    virtual void check() = 0;
    virtual void takeDamage(int damage, short direction = 0); //Cuando recibe daño, le baja la salud y si llega a cero cambia su estado

    static void setPlayer(Player *newPlayer);   
    static void setBlocks(QVector<Block *> *newBlocks);
    static void setEnemies(QList<Enemy *> *newEnemies);
    static Player *getPlayer();

    bool getInmu() const;

    short getDirection() const;

protected:
    virtual void attack() = 0; //cada enemigo podra tener su propia forma de atacar
    virtual void changeDirection();
    virtual void collidesWithPlayer(); //colisionara mientras este vivo
    virtual void collidesWithWeapon(); //colisionara mientras no sea inmune, y la duracion dele stado dependera del tiempo de ataque del armar, asi solo podra recibir un hit por cada ataque del arma
    virtual void die(); //animacion demuerte y posterior delete de contenedor, scene y memoria. Si se bugea no se eliminara, si no que se cambiara de estado para que no pueda seguir interactuando y cambiara  aun sprite invisible
    virtual void dealDamage(); //Daño al jugador cuando hace contacto con el enemigo
    bool state; //vivo o muerto
    bool inmu; //si es inmune al daño
    int atk; //puede ser statico, al ataque es igual para todos
    int *health;
    int *maxHealth; //la vida maxima es igual para todos.
    short direction; //direction donde mira el enemigo. 0=abajo, 1=izquierda, 2=derecha, 3=arriba
    unsigned int stepsDie;
    HealthBar *healthbar;
    static Player *player;
    static QVector<Block*> *blocks;
    static QList<Enemy*> *enemies;
};

#endif // ENEMY_H
