#pragma once
#include "Weapons.h"
class ExcaliburMorgan : public Weapons
{
public:
    ExcaliburMorgan();

    double specialWeaponAttack(double baseDamage) override;
    void onTurnStart(Player* player) override;
    std::string getSpecialName() override;
};

