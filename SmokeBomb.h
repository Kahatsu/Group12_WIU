#pragma once
#include "Consumables.h"
class SmokeBomb :
    public Consumables
{
public:
    SmokeBomb();

    void useConsumable(Player* player);
};

