#include "Dagger.h"
#include "Player.h"

Dagger::Dagger()
    : Weapons(2, "Dagger", 15)
{}

void Dagger::applyPassive(Player* player, double damageDealt)
{
    player->gainMoney(5);
}