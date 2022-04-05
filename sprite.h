#ifndef SPRITE_H
#define SPRITE_H
#include <QObject>
#include <QGraphicsPixmapItem>
class Sprite : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    explicit Sprite(QObject *parent = nullptr);
    /*!
     * \brief setSize estable el tamaño de los frames en pixiles
     * \param w pixiles de ancho
     * \param h pixiles de largo
     */
    void setSize(unsigned int w, unsigned int h);
    void setSprite(QString spriteName);
    void setFrame(unsigned int typeX, unsigned int typeY);


private:
    QPixmap sprite;
    QPixmap frame;
    unsigned int w;
    unsigned int h;

};

#endif // SPRITE_H
