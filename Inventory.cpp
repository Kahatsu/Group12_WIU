#include<string>
#include<algorithm>
#include<vector>
#include<iostream>
#include "Inventory.h"

Inventory::Inventory() {
	weapons.reserve(8);
	armors.reserve(8);
}

void Inventory::addConsumable(std::string item, int quantity) {
	consumables[item] += quantity;
}

void Inventory::removeConsumable(std::string item, int quantity) {
	consumables[item] -= quantity;

	if (consumables[item] <= 0) {
		consumables.erase(item);
	}
}

void Inventory::addWeapon(std::string weapon) {
	weapons.push_back(weapon);
}

void Inventory::dropWeapon(std::string weapon) {
	auto it = std::find(weapons.begin(), weapons.end(), weapon);

	if (it != weapons.end()) {
		weapons.erase(it);
	}
}

void Inventory::addArmor(std::string armor) {
	armors.push_back(armor);
}

void Inventory::dropArmor(std::string armor) {
	auto it = std::find(armors.begin(), armors.end(), armor);

	if (it != armors.end()) {
		armors.erase(it);
	}
}

void Inventory::clearConsole() {
	std::cout << "\033[H\033[2J" << std::flush;
}

//void Inventory::displayInventoryUI() {
//	std::cout << "1. Items  2. Weapons  3. Armors:  ";
//	int choice{};
//	std::cin >> choice;
//
//	clearConsole();
//
//	switch (choice) {
//	case 1: {
//		std::cout << "Items: \n";
//		int index = 0;
//		for (auto& item : consumables) {
//			std::cout << index + 1 << " " << item.first << "  x" << item.second << "\n";
//			index++;
//		}
//		std::cout << index + 1 << ". Escape\n";
//		std::cout << "Option: ";
//
//		int option{};
//		std::cin >> option;
//		//break out early if option is invalid
//		if (option < 1 || option > index) {
//			break;
//		}
//
//		int counter{};
//		for (auto& item : consumables) {
//			if (counter == option - 1) {
//				std::cout << "You consumed " << item.first << "\n";
//				removeConsumable(item.first, 1);
//				break;
//			}
//			counter++;
//		}
//
//		break;
//	}
//	case 2: {
//		for (int i = 0; i < weapons.size(); i++) {
//			std::cout << i + 1 << ". " << weapons[i] << "\n";
//		}
//		std::cout << weapons.size() + 1 << ". Escape\n";
//		std::cout << "Option: ";
//
//		int option{};
//		std::cin >> option;
//		//break out early if option is invalid
//		if (option < 1 || option > weapons.size()) {
//			break;
//		}
//
//		std::cout << "You have equipped " << weapons[option - 1] << "\n";
//
//		break;
//	}
//	case 3: {
//		for (int i = 0; i < armors.size(); i++) {
//			std::cout << i + 1 << ". " << armors[i] << "\n";
//		}
//		std::cout << armors.size() + 1 << ". Escape\n";
//		std::cout << "Option: ";
//
//		int option{};
//		std::cin >> option;
//		//break out early if option is invalid
//		if (option < 1 || option > armors.size()) {
//			break;
//		}
//
//		std::cout << "You have equipped " << armors[option - 1] << "\n";
//
//		break;
//	}
//	default:
//		break;
//	}
//}

void Inventory::displayInventoryUI()
{
    bool inventoryOpen = true;

    while (inventoryOpen)
    {
        clearConsole();

        std::cout << "1. Items  2. Weapons  3. Armors  4. Escape: ";

        int choice{};
        std::cin >> choice;

        clearConsole();

        switch (choice)
        {
        case 1:
        {
            std::cout << "Items:\n";

            int index = 0;

            for (auto& item : consumables)
            {
                std::cout << index + 1 << ". "
                    << item.first
                    << " x"
                    << item.second
                    << "\n";

                index++;
            }

            std::cout << index + 1 << ". Escape\n";
            std::cout << "Option: ";

            int option{};
            std::cin >> option;

            if (option >= 1 && option <= index)
            {
                int counter = 0;

                for (auto& item : consumables)
                {
                    if (counter == option - 1)
                    {
                        std::cout << "You consumed "
                            << item.first
                            << "\n";

                        removeConsumable(item.first, 1);
                        break;
                    }

                    counter++;
                }

                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

            break;
        }

        case 2:
        {
            for (int i = 0; i < weapons.size(); i++)
            {
                std::cout << i + 1
                    << ". "
                    << weapons[i]
                    << "\n";
            }

            std::cout << weapons.size() + 1
                << ". Escape\n";

            std::cout << "Option: ";

            int option{};
            std::cin >> option;

            if (option >= 1 && option <= weapons.size())
            {
                std::cout << "You have equipped "
                    << weapons[option - 1]
                    << "\n";

                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

            break;
        }

        case 3:
        {
            for (int i = 0; i < armors.size(); i++)
            {
                std::cout << i + 1
                    << ". "
                    << armors[i]
                    << "\n";
            }

            std::cout << armors.size() + 1
                << ". Escape\n";

            std::cout << "Option: ";

            int option{};
            std::cin >> option;

            if (option >= 1 && option <= armors.size())
            {
                std::cout << "You have equipped "
                    << armors[option - 1]
                    << "\n";

                std::cout << "\nPress Enter to continue...";
                std::cin.ignore();
                std::cin.get();
            }

            break;
        }

        case 4:
            inventoryOpen = false;
            break;

        default:
            break;
        }
    }
}