#include <iostream>
class Item{
public:
    Item(int x, int y, char g):x_(x),y_(y),g_(g){}
    int X(){return x_;}
    int Y(){return y_;}
    char G(){return g_;}
private:
    int x_;
    int y_;
    char g_;
    char desc_;
};