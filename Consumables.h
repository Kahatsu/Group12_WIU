#pragma once
#include "Items.h"
#include "Player.h"
class Consumables :
    public Items
{
public:
    Consumables(int weight, std::string name);

    virtual void useConsumable(Player* player) = 0;
};

