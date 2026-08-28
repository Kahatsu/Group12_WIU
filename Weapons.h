#pragma once
#include "Items.h"

class Player;
class Enemy;

class Weapons : public Items
{
protected:
    std::string specialVoiceLine;
    std::string equipVoiceLine;
    std::string equipDialogue;

private:
    double damageBonus;
    int specialManaCost;

public:
    Weapons(double weight, std::string name, double damageBonus, int specialManaCost = 10);
    double getDamageBonus();

    virtual double weaponAttack(double baseDamage);
    virtual double specialWeaponAttack(double baseDamage);
    virtual void applyPassive(Player* player, double damageDealt);
    virtual bool buffSpecial(Player* player);
    virtual int getSpecialHits();
    virtual void onTurnStart(Player* player);
    virtual void onEnemyTurn(Enemy* enemy);
    virtual void onTurnEnd();
    virtual double damageReduction(double damage);
    virtual std::string getSpecialName();
    void shadowExtraction();
    int getSpecialManaCost();
    std::string getSpecialVoiceLine();
    std::string getEquipVoiceLine();
    std::string getEquipDialogue();
};