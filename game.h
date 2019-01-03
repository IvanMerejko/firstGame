#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include "player.h"
#include "score.h"
#include "health.h"
class Game : public QGraphicsView
{
public:
  Game (QWidget * parent = nullptr);
  QGraphicsScene * scene;
  Player * player;
  Score * score;
  Health * health;
};

#endif // GAME_H
