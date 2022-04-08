#ifndef SPRITE_H
#define SPRITE_H
#include <QObject>
#include <QGraphicsPixmapItem>
class Sprite : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);

    void setSprite(QString spriteName);
    /*!
     * \brief setSize establece el tamaño de los frames en pixeles
     * \param w pixeles de ancho
     * \param h pixeles de largo
     */
    void setSize(unsigned int w, unsigned int h);
    /*!
     * \brief setFrame recorta del sprite el frame a mostar en pantalla.
     * \param typeX el tipo en x, si es 2, seria el frame de la segunda columna del sprite
     * \param typeY el tipo en y, si es 2, seria el frame de la segunda fila del sprite
     */
    void setFrame(unsigned int typeX = 0, unsigned int typeY = 0);


    unsigned int getW() const;

protected:
    QPixmap sprite;
    QPixmap frame;
    unsigned int w;
    unsigned int h;
};

#endif // SPRITE_H
