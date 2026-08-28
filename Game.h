#include"Player.h"
#include "Map.h"
#include "UI.h"

#pragma once
class Game
{
private:
    Player* player;
    Map* map;
    char key;
    UI* ui;
public:
    Game();

    char getKeyPress();

    void setUpGame();

    void preGame();

    //main gameplay loop here
    void playGame();

    void runGame();

    bool checkLose();// honghonghong

    void loseGame(); //honghonghong

    void winGame(); // jervis
};