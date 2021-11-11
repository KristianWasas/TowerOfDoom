#include "player.hpp"

//Jarno's implementation:
//*DUPLICATE IMPLEMENTATIONS HAVE BEEN COMMENTED OUT*
//---------------------------------------------------------------------------------------------------------//
    
/*
Player::Player(unsigned int x, unsigned int y)        DUPLICATE
    {
        position_.x = x;
        position_.y = y;
    }

*/

/*
void Player::MovePlayer(char direction)        DUPLICATE
{
    // N = North, S = South, E = East, W = West
    switch (direction)
    {
    case('N'):
        position_.y += 1;
        break;
    case('S'):
        position_.y += -1;
        break;
    case('E'):
        position_.x += 1;
        break;
    case('W'):
        position_.x += -1;
        break;
    default:
        break;
    }

}

*/


void Player::GainXP(int amount)
{
    //Function is called every time player gains XP
    // Level 1 = 1000 XP
    // Level 2 = 3000 XP
    // Level 3 = 6000 XP
    // Level 4 = 10 000 XP
    // Level 5 = 15 000 XP
    // Level 6 = 21 000 XP
    stats_.XP += amount;
    unsigned int achieved_lvl = 0;

    if(stats_.XP > 21000)
        achieved_lvl = 6;
    else if(stats_.XP > 15000)
        achieved_lvl = 5;
    else if(stats_.XP > 10000)
        achieved_lvl = 4;
    else if(stats_.XP > 6000)
        achieved_lvl = 3;
    else if(stats_.XP > 3000)
        achieved_lvl = 2;
    else if(stats_.XP > 1000)
        achieved_lvl = 1;
    if(achieved_lvl > stats_.lvl)
        Player::LevelUP(achieved_lvl);
}

void Player::LevelUP(unsigned int achieved_lvl)
{
    //Initially all stats are 1
    //Stats go up by every lvl gained
    stats_.lvl = achieved_lvl;
    stats_.Damage = 1 + achieved_lvl;
    stats_.MAX_HP = 1 + achieved_lvl;
    stats_.MAX_Shields = 1 + achieved_lvl;
}

void Player::CollectItem(std::string name, unsigned int amount)
{
    if(inventory_.items.find(name) == inventory_.items.end())
        inventory_.items[name] = amount;
    else
        inventory_.items[name] += amount;
    // Delete item from map    <- NOT YET IMPLEMENTED
    // Might have to set inventory image and number text too if Visual
}

//---------------------------------------------------------------------------------------------------------//
