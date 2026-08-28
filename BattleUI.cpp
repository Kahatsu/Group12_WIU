#include "BattleUI.h"
#include <iostream>
#include <conio.h>
#include "Enemy.h"
#include "KanshouBakuya.h"
#include "textUtils.h"
#include "Ea.h"
#include "ShadowMonarch.h"
#include <cstdlib>
#include "Miku.h"
#include "StatueOfGod.h"
#include "BossMusic.h"
#include "Enemy.h"


void BattleUI::showBattle(Player& player, Enemy& enemy)
{
    bool moved = false;
    while (enemy.getHealth() > 0 && player.getHealth() > 0 && !player.getEscaped()) {
        system("cls");

        std::cout << "==================================================" << std::endl;
        std::cout << "                    BATTLE                        " << std::endl;
        std::cout << "==================================================" << std::endl;

        std::cout << std::endl;

        // Enemy
        std::cout << "                         [ " << enemy.getName() << " ]" << std::endl;
        std::cout << "                         HP: "
            << enemy.getHealth()
            << "/"
            << enemy.getMaxHealth()
            << std::endl;
        Miku* miku = dynamic_cast<Miku*>(&enemy);

        if (miku != nullptr && miku->isSecondPhase())
        {
            std::cout << "                    !!! MIKU BEAM IN "
                << miku->getPhase2Turns()
                << " TURNS !!!"
                << std::endl;
        }

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
        std::cout << "                  MP: "
            << player.getMana()
            << "/"
            << player.getMaxMana()
            << std::endl;
        Weapons* equippedWeapon = player.getEquippedWeapon();

        if (equippedWeapon->getName() == "ShadowMonarch")
        {
            ShadowMonarch* sm = dynamic_cast<ShadowMonarch*>(equippedWeapon);

            if (sm != nullptr)
            {
                std::cout << "                  Shadows: "
                    << sm->getShadowCount()
                    << std::endl;

                if (sm->isAriseActive())
                {
                    std::cout << "                  Arise: "
                        << sm->getAriseTurns()
                        << " turns remaining"
                        << std::endl;
                }
            }
        }
        else if (equippedWeapon->getName() == "KanshouBakuya")
        {
            KanshouBakuya* kb =
                dynamic_cast<KanshouBakuya*>(equippedWeapon);

            if (kb != nullptr)
            {
                if (kb->isUBWActive())
                {
                    std::cout << "                  UBW: "
                        << kb->getUBWTurns()
                        << " turns remaining"
                        << std::endl;
                }
            }
        }

        std::cout << std::endl;

        // Battle options
        std::cout << "==================================================" << std::endl;
        std::cout << " [1] Basic Attack        [2] " << player.getEquippedWeapon()->getSpecialName() << std::endl;
        std::cout << " [3] Inventory           " << std::endl;
        std::cout << "==================================================" << std::endl;

        //player move
        player.getEquippedWeapon()->onTurnStart(&player);
        player.changeMana(10);

        //check if is sog
        StatueOfGod* SOG = dynamic_cast<StatueOfGod*>(&enemy);


        if (SOG != nullptr) {
            SOG->setAttackRestriction();
        }
        while (!moved) {
            char key = _getch();

            if (key == '1' && !player.getStun()) {

                if (SOG != nullptr && SOG->getAllowedAttack() != 1) {
                    std::cout << "The god forbidden your basic attack" << std::endl;
                    std::cout << "You lose 90% of your HP" << std::endl;

                    player.takeDamage(player.getHealth() * 90 / 100);

                    moved = true;
                    (void)_getch();
                    continue;


                }
                double damage = player.getEquippedWeapon()->weaponAttack(player.getDamage());
                enemy.takeDamage(damage);
                if (enemy.getHealth() <= 0)
                {
                    Miku* miku = dynamic_cast<Miku*>(&enemy);

                    if (miku != nullptr && !miku->isSecondPhase())
                    {
                        playBossMusic("BG\\Miku_Phase2_BG.wav");

                        miku->startSecondPhase();
                        std::cout << std::endl;
                        std::cout << "========================================" << std::endl;
                        std::cout << "       HATSUNE MIKU HAS AWAKENED!" << std::endl;
                        std::cout << "       PHASE 2 BEGINS!" << std::endl;
                        std::cout << "       Miku's HP: 300" << std::endl;
                        std::cout << "       You have 4 turns!" << std::endl;
                        std::cout << "========================================" << std::endl;

                        (void)_getch();
                    }
                }
                if (enemy.getHealth() <= 0)
                {
                    ShadowMonarch* shadowMonarch = dynamic_cast<ShadowMonarch*>(player.getEquippedWeapon());
                    if (shadowMonarch != nullptr)
                    {
                        shadowMonarch->shadowExtraction();
                    }
                }
                player.getEquippedWeapon()->applyPassive(&player, damage);
                slowPrint("DMG: " + std::to_string((int)damage), 30);
                moved = true;
                (void)_getch();
            }
            else if (key == '2' && !player.getStun())
            {
                if (SOG != nullptr && SOG->getAllowedAttack() != 2) {
                    std::cout << "The god forbidden your basic attack" << std::endl;
                    std::cout << "You lose 90% of your HP" << std::endl;

                    player.takeDamage(player.getHealth() * 90 / 100);

                    moved = true;
                    (void)_getch();
                    continue;


                }


                bool validMove = false;
                Weapons* weapon = player.getEquippedWeapon();
                if (player.getMana() < weapon->getSpecialManaCost())
                {
                    std::cout << "Not enough mana" << std::endl;
                    (void)_getch();
                    continue;
                }
                if (weapon->getName() == "LuminositeEternelle")
                {
                    validMove = weapon->buffSpecial(&player);
                }
                else if (weapon->getName() == "KanshouBakuya")
                {
                    KanshouBakuya* kb = dynamic_cast<KanshouBakuya*>(weapon);
                    if (kb != nullptr)
                    {
                        if (!kb->isUBWActive())
                        {
                            std::string voiceLine = weapon->getSpecialVoiceLine();

                            if (!voiceLine.empty())
                            {
                                playVoiceLine(voiceLine.c_str());
                            }

                            validMove = kb->buffSpecial(&player);
                        }
                        else {

                            double baseDamage = player.getDamage() + weapon->getDamageBonus();
                            std::string voiceLine = kb->getCaladbolgVoiceLine();

                            if (!voiceLine.empty())
                            {
                                playVoiceLine(voiceLine.c_str());
                            }

                            double damage = kb->caladbolgAttack(baseDamage);

                            if (damage > 0)
                            {
                                enemy.takeDamage(damage);
                                std::cout << "DMG: " << damage << std::endl;
                                validMove = true;
                            }
                        }
                    }
                }
                else if (weapon->getName() == "ShadowMonarch")
                {
                    ShadowMonarch* sm = dynamic_cast<ShadowMonarch*>(weapon);

                    if (sm != nullptr)
                    {
                        bool success = sm->buffSpecial(&player);
                        if (success)
                        {
                            std::string voiceLine = weapon->getSpecialVoiceLine();
                            validMove = true;
                        }
                    }
                }
                else
                {
                    double baseDamage = player.getDamage() + weapon->getDamageBonus();
                    int hits = weapon->getSpecialHits();
                    double totalDamage = 0;
                    std::string voiceLine = weapon->getSpecialVoiceLine();

                    if (!voiceLine.empty())
                    {
                        playVoiceLine(voiceLine.c_str());
                    }

                    for (int i = 0; i < hits; i++)
                    {
                        double damage = weapon->specialWeaponAttack(baseDamage);

                        enemy.takeDamage(damage);
                        totalDamage += damage;

                        if (hits > 1)
                        {
                            std::cout << "Hit " << (i + 1) << ": " << damage << " damage!\n";
                        }
                    }
                    if (weapon->getName() == "Bab-ilu")
                    {
                        slowPrint("FUHAHAHAHHA!", 60);
                    }

                    Miku* miku = dynamic_cast<Miku*>(&enemy);
                    if (miku != nullptr && miku->checkPhaseTransition())
                    {
                        std::cout << std::endl;
                        std::cout << "========================================" << std::endl;
                        std::cout << "       HATSUNE MIKU HAS AWAKENED!" << std::endl;
                        std::cout << "       PHASE 2 BEGINS!" << std::endl;
                        std::cout << "       Miku's HP: 300" << std::endl;
                        std::cout << "       You have 4 turns!" << std::endl;
                        std::cout << "========================================" << std::endl;

                        (void)_getch();

                        break;
                    }

                    weapon->applyPassive(&player, totalDamage);

                    if (hits > 1)
                    {
                        slowPrint("Total DMG: " + std::to_string((int)totalDamage), 40);
                        std::cout << "HITS: " << hits << std::endl;
                    }
                    else
                    {
                        slowPrint("DMG: " + std::to_string((int)totalDamage), 40);
                    }

                    validMove = true;
                }
                if (validMove)
                {
                    player.changeMana(-weapon->getSpecialManaCost());
                    moved = true;
                    (void)_getch();
                }

            }
            else if (key == '3' && !player.getStun()) {
                player.openInventory();
                moved = true;
            }

            if (player.getStun()) {
                std::cout << "You were stunned!\n";
                moved = true;
                player.setStun(false);
            }
        }
        moved = false;

        player.getEquippedWeapon()->onTurnEnd();


        // thingy
        player.getEquippedWeapon()->onEnemyTurn(&enemy);
        if (enemy.getCooldown() > 0)
        {
            slowPrint(enemy.getName() + " has been chained by Enkidu", 30);
            enemy.setCooldown(enemy.getCooldown() - 1);
            (void)_getch();
        }
        else
        {
            double enemyDamage = enemy.getDamage();
            double originalDamage = enemyDamage;

            Weapons* weapon = player.getEquippedWeapon();

            if (weapon->getName() == "KanshouBakuya")
            {
                KanshouBakuya* kb = dynamic_cast<KanshouBakuya*>(weapon);

                if (kb != nullptr)
                {
                    enemyDamage = kb->reduceDamage(enemyDamage);
                    if (enemyDamage < originalDamage)
                    {
                        slowPrint("Blocked " + std::to_string((int)(originalDamage - enemyDamage)) + " dmg", 30);
                    }
                }
            }
            else if (weapon->getName() == "Ea")
            {
                Ea* ea = dynamic_cast<Ea*>(weapon);

                if (ea != nullptr)
                {
                    enemyDamage = ea->reduceDamage(enemyDamage);
                    if (enemyDamage < originalDamage)
                    {
                        slowPrint("Blocked " + std::to_string((int)(originalDamage - enemyDamage)) + " dmg", 30);
                    }
                }
            }

            //exit before enemy attack if smokebomb
            if (player.getEscaped()) {
                break;
            }

            //enemy move
            if (enemy.getHealth() > 0) {
                //std::string voiceLine = enemy.getEnemyVoiceLines();
                //if (!voiceLine.empty())
                //{
                //    playVoiceLine(voiceLine.c_str());
                //}
                enemy.attack(&player);
            }

            (void)_getch();
        }
    }

    //give money to player after win
    if (enemy.getHealth() <= 0 && player.getHealth() > 0) {
        player.gainMoney(enemy.getMoneyToDrop());
        player.changeHealth(10);

    }
}

