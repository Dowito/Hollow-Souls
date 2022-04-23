#ifndef FURRY_H
#define FURRY_H

#include <enemy.h>
#include <motion.h>
#include <sprite.h>
#include <QGraphicsPixmapItem>
class Furry : public Enemy, public Motion
{
    Q_OBJECT
public:
    Furry(QGraphicsObject *parent);
    Furry(qreal posx, qreal posy,
          qreal velx = 10, qreal vely = 0,
          int maxHealth = 22,
          int atk = 7);
    Furry(qreal posx, qreal posy,
          qreal xmin, qreal xmax,
          bool limit,
          qreal velx = 10);

    virtual ~Furry() {};
    //Enemy
    virtual void check() override;

protected:
    /*!
     * \brief move calcula la nueva posicion y la actualiza en la escena.
     * primero se mueve en y y recibe si colisiono con algun bloque, luego revisa en x y mira si colisiono con un bloque.
     * si choque en y rebota y cambbia su vel= 0.
     * Si colision en x rebota y cambia de direccion.
     */
    virtual void move();
    /*!
     * \brief CollidesWithBlock revisa si en su nueva posicion choca con un bloque y actualiza el vector r y la posicion en scena
     */
    virtual void CollidesWithBlock();
    virtual void collidesWithBlockX(); //si choca con un Bloque "rebotara" y cambiara su direccion en x.
    virtual void collidesWithBlockY(); //si choca con Bloque "rebotara" y su velocidad sera 0
    //Enemy
    virtual void attack() override;
    virtual void changeDirection() override;
    virtual void takeDamage(int damage, short direction) override;
    //furry
    void calculateDirection();
    void checkLimits();
    //void tryFloor(); //sobra, revisa si hay borde y cambia de direccion.
    bool hit;
    bool limit;
    qreal xmin;
    qreal xmax;
};

#endif // FURRY_H
