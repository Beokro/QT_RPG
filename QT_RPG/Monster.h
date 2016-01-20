#ifndef MONSTER_H
#define MONSTER_H

#include "Life.h"
#include "Item.h"
#include "Hero.h"
#include <time.h>

using namespace std;


class Monster : public Life, public QObject, public QGraphicsPixmapItem{
private:
    //secomd is a percent 1~1000, represent perecentage/10
    vector<std::pair<Item, int> >dropItems;
    //To Do: add a vector of Equiment drop off
    int gold;
    int EXP;
    bool special = false;
    string specialType=" ";
public:
    /*Life(string name, int attack, int defense, int stamina, int intelligence,
         int stun, int weak,int HP, int MP,vector<int> skills);
     Life(string name, int attack, int defense, int stamina, int intelligence, vector<int> skills);*/
    Monster(QGraphicsItem * parent =0);
    Monster(string name, int attack, int defense, int stamina, int intelligence,
     vector<int>skills, vector<std::pair<Item, int> >dpitems, int g, int exp, QGraphicsItem * parent =0)
        : Life(name, attack, defense, stamina, intelligence,  skills), dropItems(dpitems), gold(g), EXP(exp), QGraphicsPixmapItem(parent)
    {setPixmap(QPixmap(":/images/Monster01.png")); setScale(0.1);}

    void DefeatedBy(Hero& h);
    int GiveGold();
    int GiveEXP();
//    void UpdateHP(int amount){ this->}; // ################################### TO DO ##########################
    vector<Item> DropOff();
    string To_String_Part_One();
    string To_String_Part_Two();
    void SetSpecial();
    void ShowInformation();
};


#endif // MONSTER_H
