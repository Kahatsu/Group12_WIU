#include "Game.h"
#include <conio.h>
#include "UI.h"
#include <cctype>
#include <iostream>
#include "BossMusic.h"

Game::Game()
{
    srand(static_cast<unsigned int>(time(0))); // added by honghonghong this one for the random weapons in chest thingy

    player = new Player;
    map = new Map;
    key = ' ';
    ui = new UI;
}

char Game::getKeyPress()
{
    key = _getch();
    return std::tolower(key);
}

void Game::preGame()
{
    system("cls");

    std::cout << R"(
    ___     __  __ ____   ______ ______ ____   ____   __  __ ______ __  __ _____
   /   |   / | / // __ \ / ____// __  // __ \ / __ \ / | / // ____// / / //____/
  / /| |  /  |/ // / / // __/  / /_/ // / / // / / //  |/ // / __ / / / / \__ \ 
 / ___ | / /|  // /_/ // /___ / _, _// /_/ // /_/ // /|  // /_/ // /_/ /,___/ / 
/_/  |_|/_/ |_//_____//_____//_/ |_\/_____/ \____//_/ |_/ \____/ \____//_____/

                  People die when they are killed...

                Please press F at the start of the game
                    Equip a weapon before exploring
                        (Play with sound on)


                      press any key to start)"
        << std::endl;
    getKeyPress();
}

void Game::runGame()
{
    bool playerWon = false;

    bool playerLost = ui->run(*map, *player, playerWon);

    if (playerLost)
    {
        loseGame();

        delete player;
        player = new Player();

        Chest::resetAvailableWeapons();

        delete ui;
        ui = new UI();

        runGame();
        return;
    }

    if (playerWon)
    {
        winGame();
        return;
    }
}

bool Game::checkLose()
{
    if (player->getHealth() <= 0)
    {
        return true;
    }

    return false;
}

void Game::loseGame()
{
    system("cls");
    stopBossMusic;
    playBossMusic("BG\\DeathScreen.wav");
    std::cout << R"(

__     __  ____   _    _   _____  ,_____, ______  _____  
\ \   / / / __ \ | |  | | |  __ \ |_   _||  ____||  __ \ 
 \ \_/ / | |  | || |  | | | |  | |  | |  | |__   | |  | |
  \   /  | |  | || |  | | | |  | |  | |  |  __|  | |  | |
   | |   | |__| ||_|__|_| | |__| |,_|_|_,| |____ | |__| |
   |_|    \____/  \____/  |_____/ |_____||______||_____/

               You have been defeated.

              Press any key to continue...
)" << std::endl;

    _getch();
    playBossMusic("BG\\Roaming_BG.wav");

}

void Game::winGame()
{
    system("cls");
    stopBossMusic;
    playBossMusic("BG\\VictoryScreen.wav");
    std::cout << R"(
__     __  ____   _    _   ___          ___ ,_____,  _   _
\ \   / / / __ \ | |  | |  \  \        /  / |_   _| | \ | |
 \ \_/ / | |  | || |  | |   \  \  /\  /  /    | |   |  \| |
  \   /  | |  | || |  | |    \  \/  \/  /     | |   |     |
   | |   | |__| ||_|__|_|     \   /\   /    ,_|_|_, | |\  |
   |_|    \____/  \____/       \_/  \_/     |_____| |_| \_|

            You have won!

          Press any key to continue...
)" << std::endl;
    _getch();
    playBossMusic("BG\\Roaming_BG.wav");
}