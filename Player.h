#pragma once
#include "Entity.h"
#include "Map.h"
#include "Inventory.h"
#include "Weapons.h"
#include "Armor.h"
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
    float damageMitigation;
    Weapons* equippedWeapon; //katsu
    Armor* armor;
    bool escaped; //honghong
    bool eventLocked;//added by jervis

public:
    Player();

    //change if need to cause overwite
    void takeDamage(int damage);

    double getWeight();
    double reduceWeight(double minus);
    double gainWeight(double add);

    int getMoney();
    void gainMoney(int value);
    void loseMoney(int value);

    void equip(Weapons* weapon);
    void equipWeapon(std::string weaponName);
    Weapons* getEquippedWeapon();

    void openInventory();
    void pickUpItem();

    void move(char key, Map* map);

    int getXcoord();
    void setXcoord(int new_pos);

    int getYcoord();
    void setYcoord(int new_pos);

    void addConsumable(std::string item); // honghonghong
    void addWeapon(std::string weap);//wx

    void setDamageMitigation(float percentage);

    bool getInteract();
    void setInteract();

    char getInteractType();//wx
    void useConsumable(std::string items);//wx

    bool getEscaped();
    void setEscaped(bool value);

    bool isEventLocked() const;//added by jervis
    void setEventLock(bool locked);//added by jervis

    void addArmor(std::string armor); // honghonghong armour
    bool hasArmor(std::string armor);
};