#ifndef BULLET_H
#define BULLET_H

#include "game.h"

#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject>


class Bullet : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet(QGraphicsItem * parent = nullptr);
public slots:
    void move();
};

#endif // BULLET_H
