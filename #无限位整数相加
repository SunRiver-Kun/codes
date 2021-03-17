#include<stdio.h>
#include<string.h>
int main()
{
    char a[300],b[300],c[600]="0";
    gets(a);
    gets(b);
    int y=0,i;
    char *p=a,*q=b,*x;
    while(*p!='\0') p++;
     while(*q!='\0') q++;
     p--;q--;       //让p，q指向个位
    if(strlen(a)>strlen(b))     x=c+strlen(a);  //预留c[0]
    else    x=c+strlen(b);
   while(p>=a&&q>=b)
   {
        y=(*p-'0')+(*q-'0')+y;  //用整型来判断是否大于10
    if(y<=9&&y>=0)
    {
        *x--=y+'0';
        y=0;
    }
    else if(y>=10)
    {
        y=y%10;
        *x--=y+'0';
        y=1;
    }
    p--;
    q--;
   }
    if(p<a)
  {
     while(q>=b)
   {
        y=*q-'0'+y;  //用整型来判断是否大于10
    if(y<9) {*x--=y+'0';y=0;}
    else
    {
        y=y%10;
        *x--=y+'0';
        y=1;
    }
    q--;
  }
  }
  else if(q<b)
  {
       while(p>=a)
   {
        y=*p-'0'+y;  //用整型来判断是否大于10
    if(y<9) {*x--=y+'0';y=0;}
    else
    {
        y=y%10;
        *x--=y+'0';
        y=1;
    }
    p--;
  }
  }
    c[0]=y+'0';
 if(c[0]=='0')
    for(i=1;i<strlen(c);i++)
    printf("%c",c[i]);
 else
    for(i=0;i<strlen(c);i++)
    printf("%c",c[i]);
}
