#pragma once
#include "Weapons.h"

class Sword : public Weapons
{
public:
    Sword();
    std::string getSpecialName() override;
    double specialWeaponAttack(double baseDamage) override;
};