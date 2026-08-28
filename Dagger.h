#pragma once
#include "Weapons.h"

class Dagger : public Weapons
{
public:
    Dagger();

    void applyPassive(Player* player, double damageDealt) override;
};