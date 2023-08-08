#include<stdio.h>
main()
{
    int min,h,s;
    scanf("%d",&min);
    h=min/60;
    min=min%60;
    s=min*60;
    printf("%d %d",h,s);
}
