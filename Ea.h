#pragma once
#include "Weapons.h"

class Ea : public Weapons
{
public:
    Ea();
    std::string getSpecialName() override;
    double specialWeaponAttack(double baseDamage) override;
    double reduceDamage(double damage);
};