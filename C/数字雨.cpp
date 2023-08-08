#include<iostream>
#include<string>
#include<windows.h>

#define MAXX  20
#define MAXY  50
#define MAXL  8
using namespace std;
class position
{
public:
    int x,y,length;
    position(int xx=rand()%MAXX,int yy=rand()%MAXY,int lengthx=rand()%MAXL):x(xx),y(yy),length(lengthx){}
};

int main()
{
    position pos[10];
    for(int i=0;i<10;i++)
        cout<<pos[i].x<<','<<pos[i].y<<','<<pos[i].length<<endl;

}
