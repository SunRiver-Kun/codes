#include<stdio.h>
int main()
{
    int s; //sΪ����2��ż��
    int i,j,k=0;
    int prinum[9999]; //����
    scanf("%d",&s);
    for(i=2;i<s;i++)
  {         j=2;
     while(j<i)
     {
         if(i%j==0)
            break;
         else
            j++;
     }

        if(j==i)
        {
            prinum[k]=i;
            k++;
        }

  }  //s������������¼������
  for(i=0;i<k;i++)
  {
      for(j=i;j<k;j++)
    if(prinum[i]+prinum[j]==s)
   {
        printf("%d %d",prinum[i],prinum[j]);
		goto end;
   }

  }
end:  return 0;
}
