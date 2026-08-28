#pragma once
#include "Consumables.h"
#include "Player.h"
class ManaPotion :
    public Consumables
{
private:
    double healmanaAmount;
public:
    ManaPotion();
    void useConsumable(Player* player);
};
