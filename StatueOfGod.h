#pragma once
#include "Enemy.h"
class StatueOfGod :
    public Enemy
{
   int AbilityBlocked;

public:
    StatueOfGod();

    void attack() override;
    void special_attack() override;
};

