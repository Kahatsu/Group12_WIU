#include "Bomba.h"
#include<iostream>
#include <Windows.h>
#include "textUtils.h"
#include "BossMusic.h"

Bomba::Bomba() : Enemy(5, 100, 100, "Bomba", 20)
{
    enemyVoiceLines = "Weapon\BombaExplosion.wav";
}

void Bomba::attack(Player* player) {
    if (getBattlecounter() >= 2) {
        special_attack(player);
        //reset battle counter
        changeBattlecounter(-getBattlecounter());
    }
    else {
        player->takeDamage(getDamage());
        slowPrint("Bomba bomb", 30);
    }

    changeBattlecounter(1);
}

void Bomba::special_attack(Player* player) {
    std::string voiceLine = getEnemyVoiceLines();
    playVoiceLine(voiceLine.c_str());
    player->takeDamage(50);
    slowPrint("BOMBAA!!!!", 30);
    changeHealth(-getHealth());
}
