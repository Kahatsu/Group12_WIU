#pragma once
#include "Enemy.h"

class Malenia : public Enemy
{
private:
    double lifestealPercent;

public:
    Malenia();

    void attack(Player* player) override;
    void special_attack(Player* player) override;

    double getLifesteal();
    void setLifesteal(double percent);
};
