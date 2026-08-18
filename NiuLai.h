#pragma once
#include "Enemy.h"
class NiuLai :
    public Enemy
{
public:
    NiuLai();

    void attack() override;
    void special_attack() override;

};

