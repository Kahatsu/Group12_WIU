#pragma once
#include "Weapons.h"

class Bow : public Weapons
{
public:
    Bow();

    double specialWeaponAttack(double baseDamage) override;
    std::string getSpecialName() override;
};