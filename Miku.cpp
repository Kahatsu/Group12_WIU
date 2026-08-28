#include "Miku.h"
#include <iostream>
#include "textUtils.h"
#include "BossMusic.h"
#include <Windows.h>

Miku::Miku()
    : Enemy(30, 500, 500, "Hatsune Miku", 500)
{
    secondPhase = false;
    phase2Turns = 0;
    enemyVoiceLines = "Weapon\\MikuBeam.wav";
}

void Miku::attack(Player* player)
{
    if (secondPhase)
    {
        slowPrint("MIKUDAYOO", 10);
        player->takeDamage(getDamage());

        phase2Turns--;

        std::cout << "Miku Beam countdown: "
            << phase2Turns
            << " turns remaining!" << std::endl;

        if (phase2Turns <= 0)
        {
            special_attack(player);
        }
    }
    else
    {
        player->takeDamage(getDamage());
        slowPrint("Bonk!", 10);
    }
}

void Miku::special_attack(Player* player)
{
    stopBossMusic();
    Sleep(150);
    std::string voiceLine = getEnemyVoiceLines();
    playVoiceLine(voiceLine.c_str());

    std::cout << std::endl;
    slowPrint("MIKU MIKU BEAMMMMM!!", 90);
    Sleep(300);

    player->takeDamage(9999);
}

bool Miku::isSecondPhase()
{
    return secondPhase;
}

int Miku::getPhase2Turns()
{
    return phase2Turns;
}

void Miku::startSecondPhase()
{
    secondPhase = true;
    phase2Turns = 4;
    changeHealth(350);
}

void Miku::changePhase2Turns(int value)
{
    phase2Turns += value;
}

bool Miku::checkPhaseTransition()
{
    if (getHealth() <= 0 && !secondPhase)
    {
        startSecondPhase();
        return true;
    }

    return false;
}