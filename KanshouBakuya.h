#pragma once
#include "Weapons.h"

class Player;

class KanshouBakuya : public Weapons
{
private:
    int ubwTurns;
    bool ubwActive;
    std::string caladbolgVoiceLine;
    bool caladbolgUsed;

public:
    KanshouBakuya();

    double weaponAttack(double baseDamage) override;
    double specialWeaponAttack(double baseDamage) override;

    bool buffSpecial(Player* player) override;
    void onTurnEnd() override;
    bool justActivated;
    double caladbolgAttack(double baseDamage);
    bool isUBWActive();
    virtual std::string getSpecialName();
    double reduceDamage(double damage);
    int getUBWTurns();
    std::string getCaladbolgVoiceLine();
};