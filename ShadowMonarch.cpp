#include "ShadowMonarch.h"
#include <iostream>
#include "textUtils.h"

ShadowMonarch::ShadowMonarch()
    : Weapons(5, "ShadowMonarch", 30, 40)
{
    shadowCount = 0;
    ariseActive = false;
    ariseTurns = 0;
    monarchDomainActive = false;

    specialVoiceLine = "Weapon\\Arise.wav";
    equipVoiceLine = "Weapon\\TheSystem.wav";
    equipDialogue = "Notification: You have become a player";
}
bool ShadowMonarch::buffSpecial(Player* player)
{
    if (!ariseActive)
    {
        slowPrint("Arise.", 60);
        ariseActive = true;
        ariseTurns = 4;
        slowPrint("Attack increased by " + std::to_string(shadowCount * 3) + "!", 40);

        return true;
    }

    if (!monarchDomainActive)
    {
        slowPrint("Monarch's Domain", 50);
        monarchDomainActive = true;
        slowPrint("Attack increased by an additional " + std::to_string(shadowCount * 5) + "!", 40);

        return true;
    }

    slowPrint("Domain is already active.", 40);

    return false;
}

double ShadowMonarch::weaponAttack(double baseDamage)
{
    double damage = baseDamage + getDamageBonus();

    if (ariseActive)
    {
        damage += shadowCount * 5;
        slowPrint("IGRIS WAKE UPPP", 50);

    }

    if (monarchDomainActive)
    {
        damage += shadowCount * 5;
    }
    return damage;
}

std::string ShadowMonarch::getSpecialName()
{
    if (!ariseActive)
    {
        return "Arise (40 mana)";
    }

    if (!monarchDomainActive)
    {
        return "Monarch's Domain (40 mana)";
    }

    return "Monarch's Domain";
}

void ShadowMonarch::collectShadow()
{
    shadowCount++;
    slowPrint("A shadow has joined your army", 30);
    slowPrint("Your shadows: " + std::to_string(shadowCount), 30);
}

int ShadowMonarch::getShadowCount()
{
    return shadowCount;
}

void ShadowMonarch::shadowExtraction()
{
    int chance = rand() % 100;

    if (chance < 80)
    {
        collectShadow();
    }
    else
    {
        slowPrint("Shadow Extraction has failed.", 30);
    }
}



bool ShadowMonarch::isAriseActive()
{
    return ariseActive;
}

int ShadowMonarch::getAriseTurns()
{
    return ariseTurns;
}


void ShadowMonarch::onTurnEnd()
{
    if (!ariseActive)
    {
        return;
    }

    ariseTurns--;

    if (ariseTurns <= 0)
    {
        ariseTurns = 0;
        ariseActive = false;
        monarchDomainActive = false;

        slowPrint("Your shadows have returned", 40);
    }
}