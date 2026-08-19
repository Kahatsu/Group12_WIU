#pragma once
#include "Enemy.h"
class NiuLai :
    public Enemy
{
public:
    NiuLai();

    void attack(Entity& player) override;
    void special_attack(Entity& player) override;

};

