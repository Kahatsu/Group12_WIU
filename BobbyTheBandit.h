
#include "Enemy.h"
class BobbyTheBandit :
    public Enemy
{
public:
    BobbyTheBandit();

    void attack(Player* player);
    void special_attack(Player* player);    
};
