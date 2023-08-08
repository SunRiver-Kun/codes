/*!

*/
#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
double SumMax(const double x[],const int N,const int index,const double V)
{
    if(index>N)
    {
        cout<<"错误index N = "<<N;
        exit(index);
    }
    else if(index==N-1)
    {
        if(x[index]>=V) return x[index];
        else return 0;
    }
    else if (x[index]>V)    return SumMax(x,N,index+1,V);     //跳过
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
    cout<<"请输入物体的个数:"<<endl;
    cin>>N;
    double x[N];
    cout<<"请输入每个物体的体积:"<<endl;
    for(int i=0;i<N;i++)    cin>>x[i];
    cout<<"请输入盒子体积:"<<endl;
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
    cout<<"符合条件的最大体积为："<<max<<endl;
    cout<<"i_max = "<<i_max<<endl;
}
