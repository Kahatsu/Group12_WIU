#pragma once
#include "Entity.h"
#include "Map.h"
#include "Inventory.h"
class Player :
    public Entity
{
private:
    double weight;
    int money;
    Inventory inventory;
    int x_coord;
    int y_coord;
public:
    Player();
    
    double getWeight();
    double reduceWeight(double minus);
    double gainWeight(double add);

    int getMoney();
    void gainMoney(int value);
    void loseMoney(int value);

    void equip();

   void addWeapon(std::string weapon);
   void addPotion(std::string potion);

    void openInventory();
    void pickUpItem();

    void move(char key, Map* map);

    int getXcoord();
    void setXcoord(int new_pos);
    
    int getYcoord();
    void setYcoord(int new_pos);
};

