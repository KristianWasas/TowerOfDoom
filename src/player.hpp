
#pragma once
#include "room.hpp"
#include <vector>

using namespace std;
class Player{
public:
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

private:
    int x_;
    int y_;
    char g_ = 'P';
    Room& room_;
    vector<Item> items_;
};