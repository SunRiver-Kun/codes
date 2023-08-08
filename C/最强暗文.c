#include<stdio.h>
#include<ctype.h>
#include<windows.h>
int main()
{
    int i=0,j=0,k=2,m=0,l;char a[1024];
    while(1)
    {
        a[m]=getchar();
        if(a[m]=='#')
            break;
        else if(isspace(a[m])) {a[m]='0';m++;}
      else
      {a[m]=(a[m]-'a'+i*j+k)%26+'a';
        i++;
        j+=2;
        k++;
        m++;  //最后m表示里面所含多少个数
      }
    }

    for(l=0;l<m;l++)
        printf("%c",a[l]);
        printf("\n");
        printf("%d %d %d \n",i,j,k);
        i--;
         j-=2;   //把多余的去掉
         k--;
    int x=m-1;
    char b[m];
    for(l=m-1;l>=0;l--)
    {   b[x]='0';
    if(b[x]==a[l])
      {b[x]=0;  x--;}
     else {   for(b[x]='a';b[x]<='z';b[x]++)
                if((b[x]-'a'+i*j+k)%26+'a'==a[l])
         {
         i--;
         j-=2;
         k--;
         x--;
         break;
         }
        }
    }
    for(l=0;l<m;l++)
    printf("%c",b[l]);
}
