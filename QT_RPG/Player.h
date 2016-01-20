#ifndef PLAYER_H
#define PLAYER_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Life.h"


class Player: public QObject, public QGraphicsPixmapItem, public Life{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent =0);
    void keyPressEvent(QKeyEvent * event);

};


#endif // PLAYER_H
