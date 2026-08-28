#pragma once
#include "Weapons.h"

class Scythe : public Weapons
{
public:
    Scythe();

    void applyPassive(Player* player, double damageDealt) override;
};