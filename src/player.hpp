
#pragma once
#include "room.hpp"
#include <vector>

using namespace std;
#include <string>
#include <map>
#include <list>

//Jarno's implementation
//---------------------------------------------------------------------------------------------------------//


struct Stats
{
    unsigned int lvl = 0;
    unsigned int XP = 0;
    unsigned int Damage = 1;
    unsigned int MAX_HP = 1;
    unsigned int MAX_Shields = 1;
    //Only MAX amount can be carried
    unsigned int current_HP = 1;
    unsigned int current_shields = 1;
    //Shield blocks attack
    //If no shields, HP -=1
    //Regain shields by collecting them?
};

struct Weapon
{
    std::string name;
    unsigned int Weapon_Damage = 1;
    //Someone else might do weapons and in a different way, so be ready to make according changes...
};

struct Inventory
{
    std::map<std::string, unsigned int> items;
    //Item is stored into items with name & amount;
    //constant items: Health items (health +=1), keys (open specific door), etc...
    std::list<Weapon> weapons;
};
//---------------------------------------------------------------------------------------------------------//




class Player{
public:
    //Ville's implementation:
    //---------------------------------------------------------------------------------------------------------//
    Player(int x, int y, Room& room):x_(x),y_(y),room_(room){};

    void SetRoom(Room& room){room_ = room;}

    //ERO MvTo ja setXY välillä, että MvTo tarkastaa, voiko liikkua.
    void SetXY(int x, int y){
        x_=x;
        y_=y;
    }
    // TRUE IF MOVE SUCCESSFUL
    bool MvTo(int x, int y){
        if(room_.Free(x,y)){ // MUUTA KUN TULEE TILEJÄ
            x_ = x;
            y_ = y;
            return true;
        }
        return false;
    }
    bool MvUp(){
        if(room_.Free(x_,y_-1)){
            --y_;
            return true;
        }
        return false;
    }
    bool MvDn(){
        if(room_.Free(x_,y_+1)){
            ++y_;
            return true;
        }
        return false;
    }
    bool MvLf(){
        if(room_.Free(x_-1,y_)){
            --x_;
            return true;
        }
        return false;
    }
    bool MvRg(){
        if(room_.Free(x_+1,y_)){
            ++x_;
            return true;
        }
        return false;
    }
    void AddItem(Item item){
        items_.push_back(item);
    }
    vector<Item> GetItems(){return items_;}
    // PALAUTTAA KOORDINAATIN
    int X(){return x_;}
    int Y(){return y_;}
    char G(){return g_;}
    //---------------------------------------------------------------------------------------------------------//



    //Jarno's implementation:
    //---------------------------------------------------------------------------------------------------------//


    void GainXP(int);
    //Function is called every time player gains XP
    //Every certain amount of XP levels up the player

    void LevelUP(unsigned int);
    // ^Parameter is the new level, base stats increase += 1 by every gained level
    
    void CollectItem(std::string, unsigned int);
    //Adds item name as a key to the map and sets the amount
    //---------------------------------------------------------------------------------------------------------//

    

private:
    //Ville's implementation:
    //---------------------------------------------------------------------------------------------------------//
    int x_;
    int y_;
    char g_ = 'P';
    Room& room_;
    vector<Item> items_;
    //---------------------------------------------------------------------------------------------------------//

    //Jarno's implementation:
    //---------------------------------------------------------------------------------------------------------//

    Stats stats_;
    std::map<std::string, bool> Perks_;
    //Each perks is stored as perk_name & value 1 or 0 whether perk is active or not
    //Perks could also be struct with boolean values

    Inventory inventory_;
    Weapon equipped_weapon_;


    //---------------------------------------------------------------------------------------------------------//

};

//COMMENT: do we need to add #endif?