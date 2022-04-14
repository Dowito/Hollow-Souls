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
          int maxHealth = 200,
          int atk = 30);//valores predeterminado para furry

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
    virtual void takeDamage(int damage) override;

    //void tryFloor(); //sobra, revisa si hay borde y cambia de direccion.
    //int directionX; //sobra
};

#endif // FURRY_H
