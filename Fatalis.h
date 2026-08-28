#pragma once
#include "Enemy.h"
class Fatalis :
    public Enemy
{
public:
    Fatalis();

    void attack(Player* player);
    void special_attack(Player* player);
};

