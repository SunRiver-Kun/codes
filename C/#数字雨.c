#include<stdio.h>
#include<windows.h>
#define MAX_LENGTH 7
#define MIN_LENGTH 3
#define MAP_WINDTH 78
#define MAP_LENGTH 22
#define N 15
struct xxx
{
    int length,x,y;
}a[N];
void gotoxy(int x,int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void get(int *length,int *x,int *y)
{
    *length=rand()%(MAX_LENGTH-MIN_LENGTH+1)+MIN_LENGTH;
    *y=rand()%10;
    *x=rand()%MAP_WINDTH;
}
void print(int x,int y,int length)
{
    if(y>=0)
   {
       int i,j;
    for(i=0;i<length;i++)
    {
        j=rand()%10;
        gotoxy(x,y-i);
        printf("%d",j);
    }
   }
}
void change(int *y,int *length,int i)
{
    if(*y-*length)
    {
        gotoxy(a[i].x,*y-*length+1);
        printf(" ");
    }

    if(*y==MAP_LENGTH)
    {
        if(*length)
        (*length)--;
        else
           {
               get(&a[i].length,&a[i].x,&a[i].y);
               a[i].y=0;
           }
    }
    else
        (*y)++;
}
int main()
{
    int i;
    for(i=0;i<N;i++)
    get(&a[i].length,&a[i].x,&a[i].y);
    while(1)
    {
        for(i=0;i<N;i++)
            print(a[i].x,a[i].y,a[i].length);
         Sleep(150);
         for(i=0;i<N;i++)
            change(&a[i].y,&a[i].length,i);


    }
}
