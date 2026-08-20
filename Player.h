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
    bool interact;
 char interactType;//wx
public:
    Player();
    
    double getWeight();
    double reduceWeight(double minus);
    double gainWeight(double add);

    int getMoney();
    void gainMoney(int value);
    void loseMoney(int value);

    void equip();

    void openInventory();
    void pickUpItem();

    void move(char key, Map* map);

    int getXcoord();
    void setXcoord(int new_pos);
    
    int getYcoord();
    void setYcoord(int new_pos);

    void addConsumable(std::string item); // honghonghong
    void addWeapon(std::string weap);//wx


    bool getInteract();
    void setInteract();

   char getInteractType();//wx
};

