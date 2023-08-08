#include<iostream>
using namespace std;

class Person
{
private:
    static size_t num;
public:

    Person() { num++; }
    static size_t GetNum() { return num; }
}; 
size_t Person::num = 0;


int main()
{
    cout << Person::GetNum() << endl;
    Person p;
    cout << p.GetNum();

}