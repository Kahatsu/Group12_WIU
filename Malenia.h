#pragma once
#include "Enemy.h"

class Malenia : public Enemy
{
private:
    double lifestealPercent;

public:
    Malenia();

    void attack(Player* player);
    void special_attack(Player* player);

    double getLifesteal();
};
