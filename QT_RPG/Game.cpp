#include "Game.h"
#include <QTimer>
#include <QImage>
#include <QBrush>
#include <QDebug>

static int mapLenght = 800;
static int mapHeight = 450;


Game::Game(QWidget *parent)
{
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,mapLenght,mapHeight);
    setBackgroundBrush(QBrush(QImage(":/images/background.png")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(mapLenght,mapHeight);

    //create new player
    vector<int>temp; //placeholder for vector of skills
    hero = new Hero("Saber", 1, 20, 10, 3, 4, 0,0,12, 16, temp);
    hero->setPos(200,250);
    hero->setFlag(QGraphicsItem::ItemIsFocusable);
    hero->setFocus();

    scene->addItem(hero);


    //Item(string name,string description, int buyInPrice, int sellOutPrice)
    //Initalization Test for Item
    Item Primary_HP_Potion("Primary HP Potion", "restore 10 HP", 5, 2,1);
    qDebug()<<"Buy in price for hp potion is" << Primary_HP_Potion.GetBuyPrice() << endl;
    qDebug() << "Sell out price for Hp potion is " << Primary_HP_Potion.GetSellPrice() << endl;
    //qDebug()(Primary_HP_Potion.GetDescription());



    monsterLocation.push_back(pair<int,int>(4,3));
    monsterLocation.push_back(pair<int,int>(7,5));

    int size = monsterLocation.size();

     for(int i =0; i<size; i++){
        monsters.push_back(new Monster());
        monsters[i]->setScale(0.4);
        monsters[i]->setPos(monsterLocation[i].first*50,
                            monsterLocation[i].second*50);
        scene->addItem(monsters[i]);
    }


    show();
}
