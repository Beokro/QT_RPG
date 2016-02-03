#ifndef HERO_H
#define HERO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include "Life.h"
#include "Bag.h"
#include <algorithm>
#include <time.h>
#include <iostream>
#include <cstdlib>
#include <list>
using std::endl;
using std::cin;
using std::cout;
using std::sort;
using std::list;

static int LevelToUpgrade[16] = {0,15,25,34, 44, 59, 79, 105, 140, 187, 250, 332, 443, 591, 789, 1051 };

class Hero: public QObject, public QGraphicsPixmapItem, public Life{
    Q_OBJECT
private:
    int ownership;  // distinct value stored in World class, indicating Ownership
    int coins;
    int level;
    int experience;
    int maxEXP;
    int moveDistance = 50;
    list<int>steps;
    Bag bag;
public:
    Hero(QGraphicsItem * parent =0);
    void keyPressEvent(QKeyEvent * event);

    Hero(const Hero& h,QGraphicsItem * parent =0);

    Hero(string name, int level, int attack, int defense, int stamina, int intelligence,
            int stun, int weak, int HP, int MP,  vector<int> skills, QGraphicsItem * parent =0) : QGraphicsPixmapItem(parent),
        Life(name, attack, defense, stamina, intelligence, stun, weak, HP, MP, skills) {this->level = level;  maxEXP = LevelToUpgrade[level];

                                                                                        setPixmap(QPixmap(":/images/Sabers.png"));
                                                                                        setScale(0.5);}
    Hero(string name);
    Hero& operator =(const Hero & h);
    bool CheckLevelUp();
    bool CheckOwnership(Item& item);
    //void UseItem(string itemName);
    void UseItem(int itemNum);
    void UpdateLevel();   // might call CheckLevelUp()
    bool PurchaseItem(string itemName);
    bool PurchaseItem(Item item);
    void PurchaseItem(Item item, int howMany);
    bool SellItem(string itemName);
    bool SellItem(Item item);
    bool SellItem(string itemName, int howMany);
    bool UseItem(int itemNum, Hero &h, Monster &m);
    // Get Methods for player
    int GetLevel(){ return this->level; }
    int GetCoins(){ return this->coins; }
    int GetEXP(){ return this->experience; }
    int GetMaxEXP() {return this->maxEXP;}
    Bag GetBag(){ return this->bag; }
    void PrintLevel();
    void PrintCoins();
    void PrintEXP();
    void ReportStatus();
    // string GetBag() { return bag.ToString(); }
    void GainItem(Item i);
    void GainCoins(int i) { coins += i; }
    void GainEXP(int i) { experience += i; UpdateLevel(); }

    void UseSkill(int skillNum);
    void SkillsToString(){}   /// #####################
    //bool WearEquip(Equipment equ);
    //bool TakeOffEquip(Equipment equ);

    void ResetHP() {if(HP<totalHP/2) HP = totalHP/2;}
    int getDire() {if(steps.size()>0){int temp = steps.front(); steps.pop_front();return temp;}return -1;}
};

#endif // HERO_H
