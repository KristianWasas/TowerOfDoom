#include "terminal_graphics.hpp"
#include <unistd.h>
#include <time.h>

//KUINKA MONTA FRAMEA/SEKUNTI
#define FRATE 2

int main(){
    int sx=8;
    int sy=12;
    Graph gfx(sx,sy);
    int x=0;
    int y=0;
    gfx.Hash();

    while(true){
        usleep(1000000/FRATE); //NUKKUU MIKROSEKUNTEJA
      if(y == 0 && x+1 < sx ){x++;}
       else if(x+1==sx && y+1<sy){y++;}
        else if(y+1==sy && x>0){x--;}
        else if(x==0 && y>0){y--;}
        gfx.ChPx(x,y,'O');
        gfx.Print();
        gfx.ChPx(x,y,'X');
    }

    return 0;
}

