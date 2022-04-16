#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include <QGraphicsRectItem>
class Block : public QObject , public QGraphicsRectItem
{
    Q_OBJECT
public:
    Block() {};
    explicit Block(QPointF pos , unsigned int width, unsigned int height, QObject *parent = nullptr);
    Block(qreal posx, qreal posy , unsigned int width, unsigned int height, QObject *parent = nullptr);
};

#endif // BLOCK_H
