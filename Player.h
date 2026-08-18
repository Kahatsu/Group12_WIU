#pragma once
class Player
{
private:
    int x;
    int y;

    int health;
    int maxHealth;

public:
    Player();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int getX() const;
    int getY() const;

    int getHealth() const;
};
