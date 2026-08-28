#include "KanshouBakuya.h"
#include "Player.h"
#include <iostream>
#include "textUtils.h"
#include <Windows.h>


KanshouBakuya::KanshouBakuya()
    : Weapons(5, "KanshouBakuya", 20, 50)
{
    ubwTurns = 0;
    ubwActive = false;
    caladbolgUsed = false;
    justActivated = false;
    specialVoiceLine = "Weapon\\UnlimitedBladeWorks.wav";
    caladbolgVoiceLine = "Weapon\\Caladbolg.wav";
    equipVoiceLine = "Weapon\\TraceOn.wav";
    equipDialogue = "Trace On";
}

double KanshouBakuya::weaponAttack(double baseDamage)
{
    double damage = baseDamage + getDamageBonus();

    if (ubwActive && ubwTurns > 0)
    {
        slowPrint("Trace on", 30);
        damage *= 1.5;

    }

    return damage;
}

double KanshouBakuya::specialWeaponAttack(double baseDamage)
{
    double damage = baseDamage;

    if (ubwActive && ubwTurns > 0)
    {
    }

    return damage;
}

bool KanshouBakuya::buffSpecial(Player* player)
{
    if (ubwActive)
    {
        slowPrint("Reality marble already active", 20);
        return false;
    }
    slowPrint("So... as I pray", 150);
    Sleep(600);
    slowPrint("Unlimited Blade Works!", 120);
    std::cout << "( UBW deployed for 4 turns, 50% dmg to basic ATK and 30% dmg reduction while active )" << std::endl;
    ubwTurns = 4;
    ubwActive = true;
    justActivated = true;
    caladbolgUsed = false;

    return true;
}

void KanshouBakuya::onTurnEnd()
{
    if (!ubwActive)
    {
        return;
    }

    if (justActivated)
    {
        justActivated = false;
        return;
    }

    ubwTurns--;

    if (ubwTurns <= 0)
    {
        ubwTurns = 0;
        ubwActive = false;

        slowPrint("Unlimited Blade Works has ended", 30);
    }
}

double KanshouBakuya::caladbolgAttack(double baseDamage)
{
    if (caladbolgUsed)
    {
        slowPrint("Caladbolg has already been used", 20);

        return 0;
    }
    slowPrint("Caladbolg!", 80);
    caladbolgUsed = true;

    return baseDamage * 2.5;
}

bool KanshouBakuya::isUBWActive()
{
    return ubwActive;
}

std::string KanshouBakuya::getSpecialName()
{
    if (ubwActive && !caladbolgUsed)
    {
        return "Caladbolg (50 Mana)";
    }

    if (ubwActive && caladbolgUsed)
    {
        return "Caladbolg (Used)";
    }
    return "UnlimitedBladeWorks (50 Mana)";
}

double KanshouBakuya::reduceDamage(double damage)
{
    if (ubwActive)
    {
        slowPrint("Rho Aias!", 20);
        return damage * 0.7;
    }

    return damage;
}

int KanshouBakuya::getUBWTurns()
{
    return ubwTurns;
}

std::string KanshouBakuya::getCaladbolgVoiceLine()
{
    return caladbolgVoiceLine;
}