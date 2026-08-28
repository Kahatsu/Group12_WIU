#pragma once
#include "Enemy.h"
class NiuLai :
    public Enemy
{
public:
    NiuLai();

    void attack(Player* player);
    void special_attack(Player* player) override;
};

