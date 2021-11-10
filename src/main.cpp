#include "terminal_graphics.hpp"
#include "room.hpp"
#include "player.hpp"
#include <unistd.h>
#include <time.h>
using namespace std;


int main(){
    int szx=24;
    int szy=12;
    Room room(szx,szy); // LUO HUONE
    Item i1(8,7,'I');
    Item i2(20,9,'X');
    Item i3(5,1,'O');
    room.AddItem(i1);
    room.AddItem(i2);
    room.AddItem(i3);
    room.RandGen(2,2);
    Player player(2,2,room); //LUO PELAAJA
    Graph gfx(szx,szy); //LUO GRAFIIKKA
    int x=0;
    int y=0;
    char inp=0; // INP CHAR
    gfx.DrawRoom(room, player); //PIIRRÄ HUONE GRAFIIKKA OBJEKTIN ARRAYHYN
    gfx.Print(); //PIIRRÄ GRAFIIKKA ARRAY TERMINAALIIN

    //PELI LOOPPI, JOTA PYÖRITETÄÄN KUNNES PELI LOPPUU
    while(true){
        cout << "Use wasd and enter to move, input Q to quit, R to regenerate map" << endl;
        cout << "You have: ";
        for(auto itemi: player.GetItems()){
            cout << itemi.G();
            cout << ", ";
        }
        cout << endl;

        usleep(100000); // tavallaan turha
        while(inp==0){cin >> inp;} // ODOTA TÄSSÄ KUNNES TULEE INPUT
        if(inp == 'w'){player.MvUp();}
        if(inp == 's'){player.MvDn();}
        if(inp == 'a'){player.MvLf();}
        if(inp == 'd'){player.MvRg();}
        if(inp == 'Q'){break;}
        if(inp == 'R'){room.RandGen(player.X(),player.Y());}
        /*
            TÄSSÄ VÄLISSÄ TAPAHTUISI KAIKKI EVENTIT JA VIHOLLISTEN LIIKKEET TMS.
        */
        for(auto itemi: room.GetItems()){
            if(player.X()==itemi.X() && player.Y()==itemi.Y()){
                true;
                //TÄHÄN POISTO
            }
        }

        inp = 0;
        gfx.DrawRoom(room,player);
        gfx.Print();
        
    }
    system("Clear");
    cout << "Thanks for playing :)" << endl;

    return 0;
}

