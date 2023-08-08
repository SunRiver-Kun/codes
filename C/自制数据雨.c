#include<stdio.h>
#include<windows.h>
#define x 40
#define y 30
#define z 100
void fun(char a,int n)
{
    int i;
    for(i=0;i<n;i++)
        printf("%c",a);
}
int main()
{   int i,a;
    while(1)
    {
        for(i=0;i<x;i++)
        {
            a=rand()%x;
            fun('1',a);
            fun(' ',y);
            fun('1',z-a-y);
            printf("\n");
        }
        Sleep(100);
        system("cls");
    }
}
