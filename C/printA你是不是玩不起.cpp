#include<iostream>
#include<iomanip>
#include<typeinfo>
using namespace std;
void printA(int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<setw(n-i);
        for(j=0;j<1+2*i;j++)
            cout<<'A';
        cout<<endl;
    }
    for(i=1;i<n;i++)
    {
        cout<<setw(1+i);
        for(j=0;j<1+2*(n-1-i);j++)
        cout<<'A';
        cout<<endl;
    }
}

int main()
{
    cout<<"ÌâÄ¿£º\n";
     printA(5);
     cout<<"ÎÒ£º\n";
    int n;
    cin>>n;
    while(n!=0)
    {
        printA(n);
        cin>>n;
    }
}
