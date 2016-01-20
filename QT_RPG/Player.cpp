#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    qDebug()<<"left\n";
    setPixmap(QPixmap(":/images/Sabers.png"));
    setScale(0.5);

}

void Player::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_Left){
        if(pos().x()>0)
            setPos(x()-80,y());
    }
    else if (event->key() == Qt::Key_Right){
        if(pos().x()<700)
            setPos(x()+80,y());
    }
    else if(event->key() == Qt::Key_Up){
        if(pos().y()>0)
            setPos(x(),y()-80);
    }
    else if(event->key() == Qt::Key_Down){
        if(pos().y()<700)
            setPos(x(),y()+80);
    }
}
