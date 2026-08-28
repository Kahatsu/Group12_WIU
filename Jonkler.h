#pragma once
#include "Enemy.h"
class Jonkler :
    public Enemy
{
public:
    Jonkler();

    void attack(Player* player);
    void special_attack(Player* player);
};

