#pragma once
#include "Enemy.h"
class Bomba :
    public Enemy
{
public:
    Bomba();

    void attack(Player* player);
    void special_attack(Player* player);
};

