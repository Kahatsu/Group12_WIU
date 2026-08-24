#pragma once
#include "Enemy.h"
class CasperGhost :
    public Enemy
{
public:
    CasperGhost();

    void attack(Player* player);
    void special_attack(Player* player);

};