#include "NiuLai.h"
#include<iostream>
#include "BossMusic.h"
#include "RandomNumGenerator.h"
#include "textUtils.h"
#include "Enemy.h"

NiuLai::NiuLai() :Enemy(25, 100, 100, "NiuLai", 20)
{
	enemyVoiceLines = "Weapon\\Mama.wav";
}



void NiuLai::attack(Player* player) {
    RandomNumGenerator rannum;

    if (rannum.getRandomNum(1, 100) <= 40)
    {
        std::string voiceLine = getEnemyVoiceLines();
        playVoiceLine(voiceLine.c_str());
        special_attack(player);
        slowPrint("Mamaaaaaaa", 100);

    }
    else
    {
        player->takeDamage(getDamage());
        slowPrint("MY COMPUTERRRR", 30);
    }
}


void NiuLai::special_attack(Player* player) {
	player->takeDamage(35);
}