#include "bullet.h"
#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QObject>
#include <QList>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "game.h"
extern Game* game;
Bullet::Bullet(QGraphicsItem * parent ) : QObject () , QGraphicsPixmapItem (parent){
    this->setPixmap(QPixmap(":/Images/ball.png"));
    auto timer = new QTimer();
    connect(timer , SIGNAL(timeout()), this , SLOT(move()));
    timer->start(50);
}

void Bullet::move(){
  auto colliding_items = this->collidingItems();
  for(auto it : colliding_items){
      if(typeid(*it) == typeid(Enemy)){
          //increase the score
          game->score->increase();
          scene()->removeItem(it);
          scene()->removeItem(this);
          delete it;
          delete this;
          return;
        }
    }

  this->setPos(this->x() , this->y() - 10);
  if(this->pos().y() < 0){
      scene()->removeItem(this);
      delete this;
    }
}
