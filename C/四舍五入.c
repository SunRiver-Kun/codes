#include<stdio.h>
main()
{
    float a;
    scanf("%f",&a);
    a=a*100+0.5;   //0.789���78.9+0.5=79.4(����2λС����100)
    a=a/100;  //0.794
    printf("%.2f",a);  //0.79
}
