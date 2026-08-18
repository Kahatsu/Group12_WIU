#pragma once
class Player
{
private:
    int x;
    int y;

public:
    Player();

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int getX() const;
    int getY() const;
};

