#include<iostream>
using namespace std;
//求最大公约数(辗转相除法)
int gcd(int a, int b)
{
    return !b ? a : gcd(b, a%b);
}
//求最小公倍数, a * b == gcd * lcm
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
//质数分解
void DevideInprime(int num)
{
    cout << num << " = ";
    if (num < 2)
    {
        cout << num << endl;
        return;
    }
    for (int i = 2; i <= num; ++i)
    {
        while (num%i==0) 
        {
            num /= i;
            cout << i ;
            if (num != 1)
                cout << " * ";
        }
    }
    cout << endl;
}
int main()
{
    int a, b;
    while (cin>>a>>b)
    {
        cout << lcm(a, b) << endl;
    }
}
