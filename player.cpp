#include "player.h"
#include "bullet.h"
#include "enemy.h"
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QMediaPlayer>
Player::Player(QGraphicsItem* parent) : QGraphicsPixmapItem(parent){
    setPixmap(QPixmap(":/Images/tank.png"));

    bulletSound = new QMediaPlayer();
    bulletSound->setMedia(QUrl("qrc:/sounds/bullet.mp3"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left && this->pos().x() > 0){
            this->setPos(this->x()-10, this->y());

         } else if (event->key() == Qt::Key_Right && this->pos().x()  < scene()->width()){
            setPos(x()+10,y());
         } else if (event->key() == Qt::Key_Space){
            auto bullet = new Bullet();


            bullet->setPos(this->x() + 50 , this->y());
            scene()->addItem(bullet);

         if(bulletSound->state() == QMediaPlayer::PlayingState){
              bulletSound->setPosition(0);
          } else if (bulletSound->state() == QMediaPlayer::StoppedState){
             bulletSound->play();
          }
      }
}

void Player::spawn(){
  auto enemy = new Enemy(scene()->width());
  scene()->addItem(enemy);
}
