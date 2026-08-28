#pragma once
#include <string>

class Entity {
private:
    double damage;
    // health is the entity's current health,
    // max_health is the maximum health the entity can have
    double health;
    double max_health;
    int cooldown;

    int mana;
    int max_mana;

    std::string name;
    int DOTcounter;

    bool stun;

public:
    Entity(double d, double h, double mh, int m, int mm, std::string n);

    // call this function to let enemy take damage
    void takeDamage(double damageTaken);

    double getDamage();

    // used to apply buffs/debuffs
    void changeDamage(double change);

    double getHealth();
    void changeHealth(double change);

    double getMaxHealth();
    void changeMaxHealth(double change);

    int getCooldown();
    void setCooldown(int new_cooldown);

    // Mana
    int getMana();
    void changeMana(int change);

    int getMaxMana();
    void changeMaxMana(int change);

    // Damage over time (DOT)
    void changeDOTCounter(int value);
    int getDOTCounter();
    void takeDot(int damage);

    std::string getName();

    bool getStun();
    void setStun(bool state);
};