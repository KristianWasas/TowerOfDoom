#pragma once

#include <vector>
#include <time.h>
#include <iostream>

#include <unistd.h>
#include "item.hpp"
#include <stdlib.h> //RANDOM

using namespace std;
class Room{
public:
    Room(int szx, int szy):szx_(szx), szy_(szy){
        room_.resize(szy_,vector<char>(szx_)); //CHARIN TILALLE TILE OBJEKTI
       int col = 0;
        int row = 0;
        while(row < szy_){
            while(col < szx_){
                room_[row][col]=0;
                col++;
            }
            row++;
            col = 0;
        }
    }
    // TÄMÄ SATUNNAISGENEROI MAPPEJA; EI KOVIN TÄRKEÄ
    void RandGen(int x, int y){
        cout << "GENERATING" << endl;
        srand(time(NULL));
        int col = 0;
        int row = 0;
        room_[y][x]=1;
        while(row < szy_){
            while(col < szx_){
                room_[row][col]=0;
                if(rand()%4 == 0){room_[row][col]=1;}
                col++;
            }
            row++;
            col = 0;
        }
        col = 0; row = 0;
        while(row < szy_){
            while(col < szx_){
                if(Free(col-1,row) && rand()%4==0){room_[row][col]=1;}
                if(Free(col+1,row) && rand()%4==0){room_[row][col]=1;}
                if(Free(col,row+1) && rand()%4==0){room_[row][col]=1;}
                if(Free(col,row-1) && rand()%4==0){room_[row][col]=1;}
                col++;
            }
            row++;
            col = 0;
        }
    }
    // 0 seinä, 1 vapaa
    void SetTile(int x, int y, char tile){
        room_[y][x] = tile;
    }
    
    // Palauttaa 0, jos ulkopuolella, myöhemmin palauttaa seinän?
    int Get(int x, int y){
        if(x >= szx_ || y >= szy_ || x < 0 || y < 0){
            return 0; //Jos yrittää ulkopuolelle, palauttaa seinän
        }
        return room_[y][x];
    }
    // Ei kerro tiletyyppiä, vaan voiko liikkua siihe
    bool Free(int x, int y){
        if(x >= szx_ || y >= szy_ || x < 0 || y < 0){
            return false; //Jos yrittää ulkopuolelle, ei vapaa
        }
        return room_[y][x]==1;
    }
    void AddItem(Item item){
        items_.push_back(item);
    }
    vector<Item> GetItems(){return items_;}
private:
    int szx_;
    int szy_;
    vector<vector<char>> room_; //CHARIN TILALLE TILE OBJEKTI, KUNHAN SE KEKSITÄÄN
    //vector<enemy> enemies_;
    vector<Item> items_;
    // Kaikenlaisia huoneenlaajuisia muuttujia tähän.
};