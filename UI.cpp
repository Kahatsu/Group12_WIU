#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include "Merchant.h"
#include "Chest.h"
#include <conio.h>
#include <iostream>
#include "Enemy.h"
#include "Entity.h"
#include "battleUI.h"
#include "NiuLai.h"
#include "Bomba.h"
#include "Fatalis.h"
#include "BobbyTheBandit.h"
#include "Golem.h"
#include "CasperGhost.h"
#include "Malenia.h"
#include "Jonkler.h"
#include "StatueOfGod.h"
#include "Miku.h"
#include "BossIntro.h"
#include "BossMusic.h"
#include "Map.h"
#include "textUtils.h"

UI::UI()
{
    player = new Player;
    map = new Map;
    enemy = new NiuLai;

    mikuDefeated = false; // jervis
}

void UI::clearScreen()
{
    system("cls");
}

void UI::showMap(Map& map, Player& player)
{
    clearScreen();

    std::cout << "========================================" << std::endl;
    std::cout << "                 DUNGEON                " << std::endl;
    std::cout << "========================================" << std::endl;

    map.drawMap();

    std::cout << "-------------------------------------------------" << std::endl;

    std::cout << "HP: "
        << player.getHealth()
        << "/"
        << player.getMaxHealth()
        << "    MANA: "
        << player.getMana()
        << "/"
        << player.getMaxMana()
        << "     ATK: "
        << player.getDamage()
        << "     GOLD: "
        << player.getMoney()
        << std::endl;

    //std::cout << "Weapon: "
    //    << player.getEquippedWeapon()->getName()
    //    << std::endl;

    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "[WASD] Move  [E] Inventory  [F] Interact  [M] Map" << std::endl;
}

void UI::showInventory(Player& player)
{
    clearScreen();

    std::cout << "========================================" << std::endl;
    std::cout << "                INVENTORY               " << std::endl;
    std::cout << "========================================" << std::endl;
    std::cout << std::endl;

    player.openInventory();
}

void UI::showCombat(Player& player, Enemy& enemy)
{
    std::cout << enemy.getHealth();

    while (player.getHealth() > 0 && enemy.getHealth() > 0 && !player.getEscaped())
    {
        BUI.showBattle(player, enemy);
    }
    //reset escape
    player.setEscaped(false);

    // Reset enemy health to max after battle //shouldnt need cause will delete anyways
    //enemy.changeHealth(enemy.getMaxHealth() - enemy.getHealth());
}


//void UI::showOccurrence()
//{
//    clearScreen();
//
//    std::cout << "========================================" << std::endl;
//    std::cout << "               OCCURRENCE               " << std::endl;
//    std::cout << "========================================" << std::endl;
//}

void UI::showMerchant(Player& player)
{
    clearScreen();

    Merchant merchant;
    merchant.openShop(&player);
}

void UI::showChest(Player& player, Chest& chest)
{
    clearScreen();

    chest.openby(&player);
}

bool UI::run(Map& map, Player& player, bool& playerWon)
{
    map.loadMap(0);

    // put coordinates of chests here
    // eg. Chest(5, "", "Smokebomb", 17, 27);
    chests.push_back(Chest(5, "", "SmokeBomb", 11, 11));
    chests.push_back(Chest(5, "", "SmokeBomb", 24, 11));
    chests.push_back(Chest(5, "", "SmokeBomb", 27, 11));
    chests.push_back(Chest(5, "", "SmokeBomb", 47, 18));
    chests.push_back(Chest(5, "", "SmokeBomb", 21, 31));
    chests.push_back(Chest(5, "", "SmokeBomb", 51, 35));
    chests.push_back(Chest(5, "", "SmokeBomb", 17, 34));
    chests.push_back(Chest(5, "", "SmokeBomb", 20, 43));
    chests.push_back(Chest(5, "", "SmokeBomb", 50, 50));
    chests.push_back(Chest(5, "", "SmokeBomb", 12, 52));
    chests.push_back(Chest(5, "", "SmokeBomb", 20, 54));
    chests.push_back(Chest(5, "", "SmokeBomb", 43, 54));
    chests.push_back(Chest(5, "", "SmokeBomb", 54, 54));
    chests.push_back(Chest(5, "", "SmokeBomb", 35, 58));


    showMap(map, player);

    bool gameRunning = true;

    while (gameRunning)
    {
        char input = _getch();

        if (input == 'w' ||
            input == 'W' ||
            input == 'a' ||
            input == 'A' ||
            input == 's' ||
            input == 'S' ||
            input == 'd' ||
            input == 'D' ||
            input == 'f' ||
            input == 'F' )
        {
            player.move(input, &map);

            if (player.getInteract())
            {
                if (player.getInteractType() == 'M')
                {
                    showMerchant(player);
                }
                else if (player.getInteractType() == 'C')
                {
                    Chest* chest = getNearbyChest(player);

                    if (chest != nullptr)
                    {
                        showChest(player, *chest);
                    }
                }

                else if (player.getInteractType() == 'G')
                {
                    player.move('G', &map);
                }
                else if (player.getInteractType() == 'A')
                {
                    enemy = new Malenia;

                    bossIntro(player, *enemy);
                    showCombat(player, *enemy);
                    stopBossMusic();
                    playBossMusic("BG\\Dungeon_BG.wav");
                }
                else if (player.getInteractType() == 'F')
                {
                    enemy = new Fatalis;

                    bossIntro(player, *enemy);
                    showCombat(player, *enemy);
                    stopBossMusic();
                    playBossMusic("BG\\Dungeon_BG.wav");
                }
                else if (player.getInteractType() == 'L')
                {
                    enemy = new Miku;

                    bossIntro(player, *enemy);
                    showCombat(player, *enemy);

                    stopBossMusic();
                    playBossMusic("BG\\Dungeon_BG.wav");

                    if (enemy->getHealth() <= 0) // added to check whether miku alive or not
                    {
                        mikuDefeated = true;

                        // Spawn the exit
                        map.updateMap('X', 87, 34);

                        std::cout << "\nMiku has been defeated!\n";
                        std::cout << "A mysterious portal has appeared...\n";
                        std::cout << "Find it and escape the dungeon!\n";

                        (void)_getch();
                    }
                }

                else if (player.getInteractType() == 'S')
                {
                    enemy = new StatueOfGod;

                    bossIntro(player, *enemy);
                    showCombat(player, *enemy);
                    stopBossMusic();
                    playBossMusic("BG\\Dungeon_BG.wav");
                }

                else if (player.getInteractType() == 'X')
                {
                    if (mikuDefeated)
                    {
                        playerWon = true;
                        return false;
                    }
                }

                player.setInteract();
            }
            else
            {
                encounterEnemy(player, enemy);
            }

            // Check if player died after combat
            if (player.getHealth() <= 0)
            {
                return true;
            }

            showMap(map, player);
        }

        else if (input == 'e' || input == 'E')
        {
            showInventory(player);
            showMap(map, player);
        }

        else if (input == 'p' || input == 'P')
        {
            gameRunning = false;
        }

        else if (input == 'm' || input == 'M')
        {
            clearScreen();
            map.drawFullMap();
            std::cout << "\nPress any key to return..." << std::endl;
            _getch();
            showMap(map, player);
        }

    }

    return false;
}

void UI::encounterEnemy(Player& player, Enemy* enemy)
{
    int percent{};
    int encounter{};
    RandomNumGenerator ranNum;

    percent = ranNum.getRandomNum(1, 100);
    encounter = ranNum.getRandomNum(1, 6);

    switch (encounter) {
    case 1:
        enemy = new Jonkler;
        break;
    case 2:
        enemy = new Golem;
        break;
    case 3:
        enemy = new Bomba;
        break;
    case 4:
        enemy = new BobbyTheBandit;
        break;
    case 5:
        enemy = new CasperGhost;
        break;
    case 6:
        enemy = new NiuLai;
        break;
    default:
        break;
    }

    // 10% chance
    if (percent < 8)
    {
        showCombat(player, *enemy);
    }
    else if (percent >8 && percent < 11) {
        event.occurencegenerator(player);
    }
}

// chest thingy
Chest* UI::getNearbyChest(Player& player)
{
    int playerX = player.getXcoord();
    int playerY = player.getYcoord();

    std::cout << "Player position: "
        << playerX << ", "
        << playerY << std::endl;

    for (auto& chest : chests)
    {
        int chestX = chest.getX();
        int chestY = chest.getY();

        std::cout << "Checking chest: "
            << chestX << ", "
            << chestY << std::endl;

        if ((chestX == playerX + 1 && chestY == playerY) ||
            (chestX == playerX - 1 && chestY == playerY) ||
            (chestX == playerX && chestY == playerY + 1) ||
            (chestX == playerX && chestY == playerY - 1))
        {
            return &chest;
        }
    }

    return nullptr;
}
