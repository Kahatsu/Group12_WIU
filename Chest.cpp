#include "Chest.h"
#include "UI.h"
#include "Player.h"
#include "Inventory.h"
#include <conio.h>
#include <iostream>


Chest::Chest() {
    money = 0;
    weapon = "";
    item = "";
    opened = false;
}

int Chest::getamtofmoney() {
	return money;
}

std::string Chest::getWeapon() {
    return weapon;
}


std::string Chest::getItem() {
    return item;
}

Chest::Chest(int m, std::string w, std::string i) {
	money = m;
	weapon = w;
	item = i;
	opened = false;
	
}


void Chest::open(Player* player)
{
    if(opened) {
        return;
    }
    
        



        std::cout << "====================================" << std::endl;
        std::cout << "                CHEST               " << std::endl;
        std::cout << "====================================" << std::endl;
        std::cout << std::endl;
        std::cout << "        You found a chest!" << std::endl;
        std::cout << std::endl;
        std::cout << "  Press any key to continue...";


        _getche();
        system("cls");
    

       
    if (money != 0) {

        player->gainMoney(money);
        std::cout << std::endl;
        std::cout << "You received " << money << " coins!" << std::endl;
        std::cout << std::endl;
       

    }

    if(weapon != "") {
        player->addWeapon(weapon);
        std::cout << std::endl;
        std::cout << "You received a " << weapon << "!" << std::endl;
        std::cout << std::endl;
        
    }
    if(item != "") {
        player->addConsumable(item);
        std::cout << std::endl;
        std::cout << "You received a " << item << "!" << std::endl;
        std::cout << std::endl;
    }
    std::cout << "Press X to quit" << std::endl;


    char c;

    do {
         c = _getche();
    } while (c != 'X' && c != 'x');
        
        opened = true;
    
       

    
    
}