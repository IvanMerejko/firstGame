#include "health.h"

#include <QFont>



Health::Health(QGraphicsTextItem *parent) : QGraphicsTextItem (parent) , health(3){
  setPlainText(QString("Health: ") + QString::number(health));
  setDefaultTextColor(Qt::blue);
  setFont(QFont("times" , 16));
}
void Health::decrement(){

  setPlainText(QString("Health: ") + QString::number(--health));
}
int Health::getHealth(){
  return health;
}
