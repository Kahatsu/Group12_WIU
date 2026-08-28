#pragma once
#include "Enemy.h"

class Miku : public Enemy
{
private:
    bool secondPhase;
    int phase2Turns;

public:
    Miku();

    void attack(Player* player) override;
    void special_attack(Player* player) override;

    bool isSecondPhase();
    int getPhase2Turns();

    void startSecondPhase();
    void changePhase2Turns(int value);
    bool checkPhaseTransition();
};