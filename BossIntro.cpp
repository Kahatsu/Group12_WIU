#include "BossIntro.h"
#include "BossMusic.h"
#include "textUtils.h"
#include <iostream>
#include <conio.h>

void bossIntro(Player& player, Enemy& enemy)
{
    system("cls");

    std::cout << "========================================" << std::endl;
    std::cout << "              BOSS ENCOUNTER            " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    if (enemy.getName() == "Malenia")
    {
        playBossMusic("BG\\Malenia_BG.wav");

        slowPrint("Malenia: You stand before the Blade of Miquella.", 30);
        slowPrint("Malenia: This is where your journey ends.", 30);
    }
    else if (enemy.getName() == "Fatalis")
    {
        playBossMusic("BG\\Fatalis_BG.wav");

        slowPrint("Fatalis: ...", 40);
        slowPrint("Fatalis: You dare challenge the Black Dragon?", 30);
        slowPrint("Fatalis: Then burn.", 40);
    }
    else if (enemy.getName() == "Statue Of God")
    {
        playBossMusic("BG\\StatueOfGod_BG.wav");

        slowPrint("*The statue gazes upon you with a grin.", 40);
        slowPrint("Statue of God: Kneel.", 60);
    }
    else if (enemy.getName() == "Hatsune Miku")
    {
        playBossMusic("BG\\Miku_Phase1_BG.wav");

        slowPrint("Miku: Hiiiii!", 30);
        slowPrint("Miku: Are you ready for my final concert?", 30);
        slowPrint("Miku: Let's make this one unforgettable!", 30);
    }

    std::cout << std::endl;
    std::cout << "Press any key to continue..." << std::endl;
    _getch();
}