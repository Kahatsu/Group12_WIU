#pragma once

#include "Player.h"
#include "Entity.h"
#include "Enemy.h"

class BattleUI
{
public:
    void showBattle(Player& player, Enemy& enemy);
};