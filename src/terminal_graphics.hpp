#pragma once

#include <iostream>
#include <vector>
#include <stdio.h>
#include "room.hpp"
#include "player.hpp"

// Tämä poistaa std:: tarpeen :)
using namespace std;
//Käytetään säilömään terminaaligrafiikoita
//Turha siinä vaiheessa, kun käytössä on GUI
class Graph {
public:
    Graph(int szx, int szy):szx_(szx), szy_(szy){
        graphics_.resize(szy_,vector<char>(szx_));
    }

    void Clear(){
        int col = 0;
        int row = 0;
        while(row < szy_){
            while(col < szx_){
                graphics_[row][col]=' ';
                col++;
            }
            row++;
            col = 0;
        }
    }
    void DrawRoom(Room room, Player player){
        for(auto i : room.GetItems()){ChPx(i.X(),i.Y(),i.G());} // Itemit piirretään ekana, jotta voivat olla seinän alla piilossa.

        int col = 0;
        int row = 0;
        while(row < szy_){
            while(col < szx_){
                if(room.Get(col,row)){graphics_[row][col]='.';}
                else{graphics_[row][col]='#';}
                
                col++;
            }
            row++;
            col = 0;
        }
        ChPx(player.X(),player.Y(),player.G());
        for(auto i : room.GetItems()){ChPx(i.X(),i.Y(),i.G());}
    }
    void ChPx(int x, int y, char c){
        graphics_[y][x]=c;
    }

    void Print(){
        system("clear");
        cout << endl;
        int col = 0;
        int row = 0;
        while(row < szy_){
            while(col < szx_){
                cout << graphics_[row][col];
                col++;
            }
            cout << endl;
            row++;
            col = 0;
        }
    }
private:
    int szx_;
    int szy_;
    vector<vector<char>> graphics_;
};