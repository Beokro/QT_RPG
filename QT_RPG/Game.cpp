#include "Game.h"
#include <QTimer>
#include <QImage>
#include <QBrush>

Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,800);

    //create new player
    hero = new Hero();
    hero->setPos(400,400);
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();

    scene->addItem(hero);


    monsterLocation.push_back(pair<int,int>(4,3));
    monsterLocation.push_back(pair<int,int>(7,8));

    int size = monsterLocation.size();

     for(int i =0; i<size; i++){
        monsters.push_back(new Hero());
        monsters[i]->setPos(monsterLocation[i].first*80,
                            monsterLocation[i].second*80);
        scene->addItem(monsters[i]);
    }


    show();
}
