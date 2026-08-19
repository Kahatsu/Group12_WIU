#pragma once
#include "Items.h"
class Weapons :
    public Items
{
private:
    double damage;
public:
    Weapons(double weight);

    virtual double weaponAttack() = 0;
    
    virtual double specialWeaponAttack() = 0;
};

