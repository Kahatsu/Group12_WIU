#include "BattleUI.h"
#include <iostream>
#include <conio.h>
#include "Enemy.h"

void BattleUI::showBattle(Player& player, Enemy& enemy)
{
    std::cout << "IMHERE\n";
    //system("cls");

    std::cout << "==================================================" << std::endl;
    std::cout << "                    BATTLE                        " << std::endl;
    std::cout << "==================================================" << std::endl;

    std::cout << std::endl;

    // Enemy
    std::cout << "                         [ ENEMY ]" << std::endl;
    std::cout << "                         HP: "
        << enemy.getHealth()
        << "/"
        << enemy.getMaxHealth()
        << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "              ~ enemy area ~" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    // Player
    std::cout << "                  [ PLAYER ]" << std::endl;
    std::cout << "                  HP: "
        << player.getHealth()
        << "/"
        << player.getMaxHealth()
        << std::endl;

    std::cout << std::endl;

    // Battle options
    std::cout << "==================================================" << std::endl;
    std::cout << " [1] Basic Attack        [2] Special Attack" << std::endl;
    std::cout << " [3] Inventory           [4] Taunt" << std::endl;
    std::cout << "==================================================" << std::endl;
}