#include <iostream>
#include <vector>
#include <stdio.h>
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
        for(auto i : graphics_){
            for(auto j : i){
                j=' ';
            }
        }
    }
    void Hash(){
        int col = 0;
        int row = 0;
        while(row < szy_){
            while(col < szx_){
                graphics_[row][col]='#';
                col++;
            }
            cout << endl;
            row++;
            col = 0;
        }
        
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