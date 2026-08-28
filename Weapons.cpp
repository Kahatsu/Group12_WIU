#include "Weapons.h"
#include "Player.h"
#include <thread>
#include <chrono>
#include <iostream>


Weapons::Weapons(double weight, std::string name, double damageBonus, int specialManaCost)
    : Items(weight, name)
{
    this->damageBonus = damageBonus;
    this->specialManaCost = specialManaCost;
}


double Weapons::getDamageBonus()
{
    return damageBonus;
}

int Weapons::getSpecialManaCost()
{
    return specialManaCost;
}

double Weapons::weaponAttack(double baseDamage)
{
    return baseDamage + damageBonus;
}

double Weapons::specialWeaponAttack(double baseDamage)
{
    return baseDamage;
}

void Weapons::applyPassive(Player* player, double damageDealt)
{}

bool Weapons::buffSpecial(Player* player)
{
    return false;
}

int Weapons::getSpecialHits()
{
    return 1;
}

void Weapons::onTurnStart(Player* player)
{}

void Weapons::onEnemyTurn(Enemy* enemy)
{}

void Weapons::onTurnEnd()
{}

double Weapons::damageReduction(double damage)
{
    return damage;
}

std::string Weapons::getSpecialName()
{
    return "Special Attack";
}

std::string Weapons::getSpecialVoiceLine()
{
    return specialVoiceLine;
}

std::string Weapons::getEquipVoiceLine()
{
    return equipVoiceLine;
}

std::string Weapons::getEquipDialogue()
{
    return equipDialogue;
}