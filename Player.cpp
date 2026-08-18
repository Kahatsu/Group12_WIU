#include "Player.h"

Player::Player()
{
    x = 0;
    y = 0;
}

void Player::moveUp()
{
    y--;
}

void Player::moveDown()
{
    y++;
}

void Player::moveLeft()
{
    x--;
}

void Player::moveRight()
{
    x++;
}

int Player::getX() const
{
    return x;
}

int Player::getY() const
{
    return y;
}