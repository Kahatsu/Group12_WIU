#pragma once
#include "Enemy.h"
class Golem :
    public Enemy
{
public:
    Golem();

    void attack(Player* player);
    void special_attack(Player* player);
};

