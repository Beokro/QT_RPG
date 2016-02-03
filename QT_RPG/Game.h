#ifndef GAME_H
#define GAME_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QtWidgets>
#include "Hero.h"
#include "Monster.h"
#include "Dungeon.h"
#include "World.h"
#include "NPC.h"
#include <vector>
using std::vector;
using std::pair;

class Game: public QGraphicsView{
public:
    Game(QWidget * parent=0);

    QGraphicsScene * scene;
    Hero * hero;
private:
    vector<pair<int,int> >monsterLocation;
    vector<Monster*>monsters;
    void mousePressEvent(QMouseEvent * event) {hero->setFocus();}
    void mouseReleaseEvent(QMouseEvent * event) {hero->setFocus();}
};



#endif // GAME_H
