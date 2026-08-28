#include "ExcaliburMorgan.h"
#include "Player.h"
#include <iostream>
#include "textUtils.h"
#include <Windows.h>


ExcaliburMorgan::ExcaliburMorgan()
    : Weapons(5, "Excalibur Morgan", 32, 70)
{
    specialVoiceLine = "Weapon\\ExcaliburMorgan.wav";
    equipVoiceLine = "Weapon\\MorganEquip.wav";
    equipDialogue = "Get out of my face";
}

double ExcaliburMorgan::specialWeaponAttack(double baseDamage)
{
    slowPrint("EXCALIBUR MORGAN!!", 120);
    Sleep(600);
    return baseDamage * 6.0;
}

void ExcaliburMorgan::onTurnStart(Player* player)
{
    double healAmount = player->getMaxHealth() - 5;
    std::cout << "You feel the corruption growing (-5 hp)" << std::endl;
    player->changeHealth(healAmount);
}

std::string ExcaliburMorgan::getSpecialName()
{
    return "ExcaliburMorgan (70 Mana)";
}