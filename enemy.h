#ifndef ENEMY_H
#define ENEMY_H
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsItem>
#include <QObject>


class Enemy : public QObject , public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy( qreal width , QGraphicsItem* parent = nullptr );
public slots:
    void move();
};

#endif // ENEMY_H
