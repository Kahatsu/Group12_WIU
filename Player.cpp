#include "Player.h"
#include <iostream>
#include <cctype>
#include "Gauntlets.h"
#include "Sword.h"
#include "Bow.h"
#include "Scythe.h"
#include "Dagger.h"
#include "LuminositeEternelle.h"
#include "BabIlu.h"
#include "Excalibur.h"
#include "KanshouBakuya.h"
#include "Ea.h"
#include "ShadowMonarch.h"
#include "ExcaliburMorgan.h"
#include "Iron_Armor.h"
#include "Diamond_Armor.h"
#include "Netherite_Armor.h"
#include "Potion.h"
#include "SmokeBomb.h"
#include "ManaPotion.h"
#include "BossMusic.h"
#include "textUtils.h"
#include "UI.h"


Player::Player() : Entity(10, 100, 100, 100, 100, "placeholder")
{
    weight = 50;
    money = 10;
    x_coord = 17;
    y_coord = 33;
    interact = false;
    interactType = ' ';
    damageMitigation = 1.0f;
    equippedWeapon = new Weapons(0, "Bare Fist", 0);
    armor = new Armor(0, "leathertunic", 1.0f);
    escaped = false;
    eventLocked = false;
}


// Take armor into account
void Player::takeDamage(int damage)
{
    int damageToTake = damageMitigation * damage;
    changeHealth(-damageToTake);
}

// add armour into inventroy
void Player::addArmor(std::string armor)
{
    inventory.addArmor(armor);
}


double Player::getWeight()
{
    return weight;
}


double Player::reduceWeight(double minus)
{
    return weight - minus;
}


double Player::gainWeight(double add)
{
    return weight + add;
}


int Player::getMoney()
{
    return money;
}


void Player::gainMoney(int value)
{
    money += value;
}


void Player::loseMoney(int value)
{
    money -= value;
}


void Player::equipWeapon(std::string weaponName)
{
    if (weaponName == "Gauntlets")
    {
        equip(new Gauntlets());
    }
    else if (weaponName == "Sword")
    {
        equip(new Sword());
    }
    else if (weaponName == "Bow")
    {
        equip(new Bow());
    }
    else if (weaponName == "Scythe")
    {
        equip(new Scythe());
    }
    else if (weaponName == "Dagger")
    {
        equip(new Dagger());
    }
    else if (weaponName == "LuminositeEternelle")
    {
        equip(new LuminositeEternelle());
    }
    else if (weaponName == "KanshouBakuya")
    {
        equip(new KanshouBakuya());
    }
    else if (weaponName == "Excalibur")
    {
        equip(new Excalibur());
    }
    else if (weaponName == "Bab-ilu")
    {
        equip(new BabIlu());
    }
    else if (weaponName == "Ea")
    {
        equip(new Ea());
    }
    else if (weaponName == "ShadowMonarch")
    {
        equip(new ShadowMonarch());
    }
    else if (weaponName == "ExcaliburMorgan")
    {
        equip(new ExcaliburMorgan());
    }
}


void Player::equip(Weapons* weapon)
{
    equippedWeapon = weapon;

    if (!weapon->getEquipVoiceLine().empty())
    {
        playVoiceLine(weapon->getEquipVoiceLine().c_str());
    }

    if (!weapon->getEquipDialogue().empty())
    {
        showEquipPopup(weapon);
    }
}

Weapons* Player::getEquippedWeapon()
{
    return equippedWeapon;
}


void Player::openInventory() // katsu
{
    std::string selectedItem = inventory.displayInventoryUI();

    if (inventory.getuseitem())
    {
        useConsumable(selectedItem);
    }
    else if (selectedItem == "Iron Armor")
    {
        armor = new Iron_Armor();
        setDamageMitigation(armor->getMitigationAmt());

        std::cout << "You have equipped " << selectedItem << "!\n";
    }
    else if (selectedItem == "Diamond Armor")
    {
        armor = new Diamond_Armor();
        setDamageMitigation(armor->getMitigationAmt());

        std::cout << "You have equipped " << selectedItem << "!\n";
    }
    else if (selectedItem == "Netherite Armor")
    {
        armor = new Netherite_Armor();
        setDamageMitigation(armor->getMitigationAmt());

        std::cout << "You have equipped " << selectedItem << "!\n";
    }
    else if (!selectedItem.empty() &&
        selectedItem != "Potion" &&
        selectedItem != "SmokeBomb" &&
        selectedItem != "Mana Potion")
    {
        equipWeapon(selectedItem);

        std::cout << "You have equipped " << selectedItem << "!\n";
    }
}


void Player::pickUpItem()
{

}


void Player::move(char key, Map* map)
{
    switch (std::tolower(key))
    {
    case 'w':
        if (map->checkMap(x_coord, y_coord - 1) == 'o')
        {
            map->updateMap('o', x_coord, y_coord);
            y_coord -= 1;
            map->updateMap('P', x_coord, y_coord);
        }
        break;

    case 's':
        if (map->checkMap(x_coord, y_coord + 1) == 'o')
        {
            map->updateMap('o', x_coord, y_coord);
            y_coord += 1;
            map->updateMap('P', x_coord, y_coord);
        }
        break;

    case 'a':
        if (map->checkMap(x_coord - 1, y_coord) == 'o')
        {
            map->updateMap('o', x_coord, y_coord);
            x_coord -= 1;
            map->updateMap('P', x_coord, y_coord);
        }
        break;

    case 'd':
        if (map->checkMap(x_coord + 1, y_coord) == 'o')
        {
            map->updateMap('o', x_coord, y_coord);
            x_coord += 1;
            map->updateMap('P', x_coord, y_coord);
        }
        break;

    case 'g':
        // Teleport to boss location
        map->updateMap('o', x_coord, y_coord);
        map->updateMap('P', 86, 34);
        x_coord = 86;
        y_coord = 34;
        break;

    case 'f':
        std::cout << "pressed f\n";

        if ((map->checkMap(x_coord + 1, y_coord) == 'M') ||
            (map->checkMap(x_coord - 1, y_coord) == 'M') ||
            (map->checkMap(x_coord, y_coord + 1) == 'M') ||
            (map->checkMap(x_coord, y_coord - 1) == 'M'))
        {
            interact = true;
            interactType = 'M';
            std::cout << "interacted\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'C') ||
            (map->checkMap(x_coord - 1, y_coord) == 'C') ||
            (map->checkMap(x_coord, y_coord + 1) == 'C') ||
            (map->checkMap(x_coord, y_coord - 1) == 'C'))
        {
            interact = true;
            interactType = 'C';
            std::cout << "interacted\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'N') ||
            (map->checkMap(x_coord - 1, y_coord) == 'N') ||
            (map->checkMap(x_coord, y_coord + 1) == 'N') ||
            (map->checkMap(x_coord, y_coord - 1) == 'N'))
        {
            interact = true;
            interactType = 'N';
            std::cout << "interacted with enemy\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'F') ||
            (map->checkMap(x_coord - 1, y_coord) == 'F') ||
            (map->checkMap(x_coord, y_coord + 1) == 'F') ||
            (map->checkMap(x_coord, y_coord - 1) == 'F'))
        {
            interact = true;
            interactType = 'F';
            std::cout << "engaged Fatalis in combat\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'A') ||
            (map->checkMap(x_coord - 1, y_coord) == 'A') ||
            (map->checkMap(x_coord, y_coord + 1) == 'A') ||
            (map->checkMap(x_coord, y_coord - 1) == 'A'))
        {
            interact = true;
            interactType = 'A';
            std::cout << "engaged Malenia in combat\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'G') ||
            (map->checkMap(x_coord - 1, y_coord) == 'G') ||
            (map->checkMap(x_coord, y_coord + 1) == 'G') ||
            (map->checkMap(x_coord, y_coord - 1) == 'G'))
        {
            interact = true;
            interactType = 'G';
            std::cout << "opened gates to boss\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'L') ||
            (map->checkMap(x_coord - 1, y_coord) == 'L') ||
            (map->checkMap(x_coord, y_coord + 1) == 'L') ||
            (map->checkMap(x_coord, y_coord - 1) == 'L'))
        {
            interact = true;
            interactType = 'L';
            std::cout << "Engaged the Big Boss Miku\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'X') || // for exit
            (map->checkMap(x_coord - 1, y_coord) == 'X') ||
            (map->checkMap(x_coord, y_coord + 1) == 'X') ||
            (map->checkMap(x_coord, y_coord - 1) == 'X'))
        {
            interact = true;
            interactType = 'X';
            std::cout << "Found the exit!\n";
        }
        else if ((map->checkMap(x_coord + 1, y_coord) == 'S') ||
            (map->checkMap(x_coord - 1, y_coord) == 'S') ||
            (map->checkMap(x_coord, y_coord + 1) == 'S') ||
            (map->checkMap(x_coord, y_coord - 1) == 'S'))
        {
            interact = true;
            interactType = 'S';
            std::cout << "engaged Statue Of God\n";
        }
        break;

    default:
        map->updateMap('P', x_coord, y_coord);
        break;
    }

    map->setPlayerXCoord(x_coord);
    map->setPlayerYCoord(y_coord);
}


int Player::getXcoord()
{
    return x_coord;
}


void Player::setXcoord(int new_pos)
{
    x_coord = new_pos;
}


int Player::getYcoord()
{
    return y_coord;
}


void Player::setYcoord(int new_pos)
{
    y_coord = new_pos;
}


void Player::addConsumable(std::string item)
{
    inventory.addConsumable(item);
}


void Player::addWeapon(std::string weap)
{
    inventory.addWeapon(weap);
}


void Player::setDamageMitigation(float percentage)
{
    damageMitigation = percentage;
}


bool Player::getInteract()
{
    return interact;
}


void Player::setInteract()
{
    interact = false;
}


char Player::getInteractType()
{
    return interactType;
}


void Player::useConsumable(std::string item)
{
    if (item == "Health Potion")
    {
        Potion potion;
        potion.useConsumable(this);
    }
    else if (item == "Mana Potion")
    {
        ManaPotion manaPotion;
        manaPotion.useConsumable(this);
    }
    else if (item == "SmokeBomb")
    {
        SmokeBomb smokebomb;
        smokebomb.useConsumable(this);
    }
    else if (item == "GOLDEN TURD")
    {
        std::cout << "You used the GOLDEN TURD\n";
        std::cout << "But it did nothing\n";
    }

    inventory.setuseitem(false);
}

bool Player::getEscaped()
{
    return escaped;
}

void Player::setEscaped(bool value)
{
    escaped = value;
}

void Player::setEventLock(bool locked) { eventLocked = locked; }//added by jervis
bool Player::isEventLocked() const { return eventLocked; }//added by jervis


bool Player::hasArmor(std::string armor)
{
    return inventory.hasArmor(armor);
}