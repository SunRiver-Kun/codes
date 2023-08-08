#include<stdio.h>
#include<string.h>
int char_abc(char a[])
{
    if(a[0]==a[1]||a[0]==a[2]||a[1]==a[2])
        return 0;
    return 1;
}
int main()
{
    int a,i,j,k;
    char x[4],y[4],z[4];
    for(i=1;i<=9;i++)
         for(j=1;j<=9;j++)
          for(k=1;k<=9;k++)
    {
        if(i!=j&&i!=k&&j!=k)
        {
            a=i*100+j*10+k;
            if(3*a>999) goto end;
            sprintf(x,"%d",a);
            sprintf(y,"%d",2*a);
            sprintf(z,"%d",3*a);
            if(strpbrk(x,y)==NULL&&strpbrk(x,z)==NULL&&strpbrk(y,z)==NULL)
                if(char_abc(x)&&char_abc(y)&&char_abc(z))
                printf("%d %d %d\n",a,2*a,3*a);
        }
    }
    end: return 0;
}
