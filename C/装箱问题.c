#include<stdio.h>
int main()
{
    int i,max_i,j,n,v,num=1;
    scanf("%d%d",&v,&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
  while(num<=n&&v>0)
  {         max_i=0;
      for(i=0;i<n;i++)
        if(a[i]>a[max_i])
            max_i=i;

    if(v>=a[max_i])
        v=v-a[max_i];

    a[max_i]=0;
        num++;
  }
    printf("%d",v);
}
/*������д��
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
double SumMax(const double x[],const int N,const int index,const double V)
{
    if(index>N)
    {
        cout<<"����index N = "<<N;
        exit(index);
    }
    else if(index==N-1)
    {
        if(x[index]>=V) return x[index];
        else return 0;
    }
    else if (x[index]>V)    return SumMax(x,N,index+1,V);     //����
    else
    {
        double max = 0 , sum = 0;
        for(int i=index+1;i<N;i++)
            {
                sum = SumMax(x,N,i,V-x[index]);
                if(max<sum) max = sum;
            }
        return max+x[index];

    }
}


int main()
{
    int N=0;
    double V = 0;
    cout<<"����������ĸ���:"<<endl;
    cin>>N;
    double x[N];
    cout<<"������ÿ����������:"<<endl;
    for(int i=0;i<N;i++)    cin>>x[i];
    cout<<"������������:"<<endl;
    cin>>V;

    double max = 0 , sum = 0 , i_max = 0;
    for(int i=0;i<N;i++)
    {
        sum = SumMax(x,N,i,V);
        if(max<sum)
           {
               max = sum;
               i_max = i;
           }
    }
    cout<<"����������������Ϊ��"<<max<<endl;
    cout<<"i_max = "<<i_max<<endl;
}



*/
