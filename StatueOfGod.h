#pragma once
#include "Enemy.h"
class StatueOfGod :
    public Enemy
{
   int AbilityBlocked;

public:
    StatueOfGod();

    void attack(Entity& player) override;
    void special_attack(Entity& player) override;
};

