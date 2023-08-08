#include<stdio.h>
#include<math.h>
void fun(float a,float b,float c)
{
    float Discriminant,root1,root2;
    Discriminant=b*b-4*a*c;
    if(Discriminant<0)
        printf("The equation has no real roots");
    else if(Discriminant==0)
        printf("%.0f",-b/(2*a));
    else
        {root1=(-b+sqrt(Discriminant))/(2*a);
        root2=(-b-sqrt(Discriminant))/(2*a);
        printf("%.0f %.0f",root1,root2);
        }
}
int main()
{
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    fun(a,b,c);
}
