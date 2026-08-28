#pragma once
#include "Weapons.h"

class BabIlu : public Weapons
{
private:
    int turnCounter;

public:
    BabIlu();

    int getSpecialHits() override;
    void onEnemyTurn(Enemy* enemy) override;
    std::string getSpecialName() override;
    double specialWeaponAttack(double baseDamage) override;
};