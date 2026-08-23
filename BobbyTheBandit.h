
#include "Enemy.h"
class BobbyTheBandit :
    public Enemy
{
    bool stolen;
    int moneysteal;
public:
    BobbyTheBandit();

    void attack(Player* player);
    void special_attack(Player* player);

    int getmoneysteal();

    
};
