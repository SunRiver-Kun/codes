#include<stdio.h>
#include<windows.h>
int main()
{
    int i=0;
    for(i=32;i<128;i++)  //32~127²ÅÊÇASCII´òÓ¡×Ö·û
    {
        if(i%8==0)
            printf("\n");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_GREEN);
        printf("%c",i);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_BLUE);
        printf("%3d",i);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),BACKGROUND_INTENSITY);
    return 0;
}
