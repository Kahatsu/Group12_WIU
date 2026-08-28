#pragma once

#include "Weapons.h"

class ShadowMonarch : public Weapons
{
private:
    int shadowCount;
    bool ariseActive;
    int ariseTurns;
    bool monarchDomainActive;

public:
    ShadowMonarch();

    double weaponAttack(double baseDamage) override;
    bool buffSpecial(Player* player) override;
    std::string getSpecialName() override;
    int getShadowCount();
    void onTurnEnd() override;
    void collectShadow();
    void shadowExtraction();
    int getAriseTurns();
    bool isAriseActive();
};