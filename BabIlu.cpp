#include "BabIlu.h"
#include "Enemy.h"
#include <cstdlib>
#include <iostream>
#include "textUtils.h"
#include <Windows.h>


BabIlu::BabIlu()
    : Weapons(5, "Bab-ilu", 20, 30)
{
    turnCounter = 0;
    specialVoiceLine = "Weapon\\GateOfBabylon.wav";
    equipVoiceLine = "Weapon\\Zasshu.wav";
    equipDialogue = "Yorokobe, Zasshu";
}

int BabIlu::getSpecialHits()
{
    return 3 + (rand() % 3);
}

void BabIlu::onEnemyTurn(Enemy* enemy)
{
    turnCounter++;

    if (turnCounter >= 2)
    {
        enemy->setCooldown(1);
        turnCounter = 0;
        slowPrint("Chains Of Heaven", 40);
    }
}

std::string BabIlu::getSpecialName()
{
    return "Gate of Babylon";
}

double BabIlu::specialWeaponAttack(double baseDamage)
{
    return baseDamage * 0.5;
}