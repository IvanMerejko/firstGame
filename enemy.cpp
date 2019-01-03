#include "enemy.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <iostream>
#include <random>
#include <QDebug>
#include <QCoreApplication>
#include <QPixmap>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include "game.h"
extern Game* game;
Enemy::Enemy(qreal width , QGraphicsItem* parent) : QObject () , QGraphicsPixmapItem (parent){
  //setPixmao(QPixmap(":/Images/PoopEmote.png"));
  setPixmap(QPixmap(":/Images/PoopEmote.png"));
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<> dis(0.0, width - 50);
  auto randomPosX = dis(gen);

  setPos(randomPosX , 0);
  auto timer = new QTimer();
  connect(timer , SIGNAL(timeout()) , this , SLOT(move()));
  timer->start(50);
}

void Enemy::move(){
  setPos(x() , y() + 5);
  if(this->y() + 100 > scene()->height()){
      scene()->removeItem(this);
      delete this;
      game->health->decrement();
      if(game->health->getHealth() == 0){
          auto items = game->items();
          for(auto item : items){
              delete item;
            }
          exit(1);
        }
    }
}
