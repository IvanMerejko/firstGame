#include "game.h"
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include <QMediaPlayer>
#include <QImage>
#include <QBrush>
#include "health.h"
Game::Game(QWidget* parent){

  scene = new QGraphicsScene();

  scene->setSceneRect(0,0 , 800 , 600);
  setBackgroundBrush(QBrush(QImage(":/Images/fon.jpg")));
  setScene(scene);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  player = new Player();

  scene->addItem(player);
  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

  player->setPos(scene->width()/2 , scene->height() - 100);

  //score
  score = new Score();
  scene->addItem(score);

  health = new Health();
  health->setPos(health->x() , health->y() + 25);
  scene->addItem(health);

  auto timer = new QTimer();
  QObject::connect(timer , SIGNAL(timeout()) , player , SLOT(spawn()));
  timer->start(2000);

  auto backMusic = new QMediaPlayer();
  backMusic->setMedia(QUrl("qrc:/sounds/music.mp3"));
  if(backMusic->state() == QMediaPlayer::PlayingState){
       backMusic->setPosition(0);
   } else if (backMusic->state() == QMediaPlayer::StoppedState){
      backMusic->play();
    }
}


