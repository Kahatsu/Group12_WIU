#pragma once
#include "Enemy.h"
class StatueOfGod :
    public Enemy
{
    bool canBlockability;

public:
    StatueOfGod();

    void attack() override;
    void special_attack() override;
};

