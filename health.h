#ifndef HEALTH_H
#define HEALTH_H
#include <QGraphicsTextItem>

class Health : public QGraphicsTextItem{
public:
  Health(QGraphicsTextItem * parent = nullptr);
  void decrement();
  int getHealth();
private:
  int health;
};

#endif // SCORE_H
