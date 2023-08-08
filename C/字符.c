#include<stdio.h>
main()
{
    char a,b;
    a=getchar();
    b=getchar();
    a=a-96;
    printf("%d,",a);
    putchar(a-32);
    printf("\n");
    printf("%d,",b);
    putchar(b-32);
    putchar('\n');


}
