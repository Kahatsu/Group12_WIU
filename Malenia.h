#pragma once
#include "Enemy.h"

class Malenia : public Enemy
{
private:
    double lifestealPercent;

public:
    Malenia();

    void attack() override;
    void special_attack() override;

    double getLifesteal();
};