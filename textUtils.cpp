#include "TextUtils.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Weapons.h"
#include <cstdlib>
#include <conio.h>
#include <string>
#include <windows.h>

void slowPrint(const std::string& text, int delay)
{
    for (char c : text)
    {
        std::cout << c << std::flush;

        std::this_thread::sleep_for(
            std::chrono::milliseconds(delay)
        );
    }

    std::cout << std::endl;
}

void slowPrintCentered(const std::string& text, int delay)
{
    int width = 45;
    int padding = (width - text.length()) / 2;

    if (padding < 0)
        padding = 0;

    std::cout << std::string(padding, ' ');
    slowPrint(text, delay);
}

void showEquipPopup(Weapons* weapon)
{
    system("cls");

    std::cout << "==================================================" << std::endl;
    std::cout << "              WEAPON EQUIPPED                    " << std::endl;
    std::cout << "==================================================" << std::endl;

    std::cout << std::endl;

    slowPrintCentered(weapon->getEquipDialogue(), 60);
    std::cout << std::endl;
    Sleep(500);

    std::cout << "             [ Press any key ]" << std::endl;

    _getch();
}