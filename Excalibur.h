#pragma once
#include "Weapons.h"

class Excalibur : public Weapons
{
public:
    Excalibur();

    double specialWeaponAttack(double baseDamage) override;
    void onTurnStart(Player* player) override;
    std::string getSpecialName() override;
};