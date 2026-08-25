#pragma once
#include "Enemy.h"
class StatueOfGod :
    public Enemy
{
private:
    int allowedAttack;   

public:
    StatueOfGod();

    void attack(Player& player);
    void special_attack(Player& player);

    void setAttackRestriction();
    int getAllowedAttack();

};