#include<iostream>

#include<string>
#include<sstream>
using namespace std;
string num2str(const double i)
{
    stringstream ss;
    ss << i;
    return ss.str();
}
double str2num(string s)
{
    double i;
    stringstream ss(s);
    ss >> i;
    return i;
}

int main()
{
    string str(num2str(1));
    cout << str << "||" << str2num(str) << endl;
}
