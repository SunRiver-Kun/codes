#include<iostream>
using namespace std;
/*总结
1. operator@ 实质是函数重载, a + b <--> a.operator(b)
2. Person a = ... //会调用构建函数
3. a = ...  //这时才是调用operator=
4.const int &a  或者 const int a 或者 int a 才能直接加常数， int &a不可以

*/

class Person
{
public:
    int value;
    Person *next=NULL;
    //运算符重载本质还是函数重载
    Person operator+(Person &other)   //a+b  <--> a.operator+(b);
    {
        cout << "调用了运算符重载+" << endl;
        this->value += other.value;
        return *this;
    }
    void operator=(Person &other)  //类成员函数重载法  a=b <--> a.operator(b)
    {
        this->value = other.value;
        this->next = other.next;  //浅拷贝
        cout << "调用了运算符重载=" << endl;
    }
    void operator=( int a)  //const int &a  或者 const int a 或者 int a 才能直接加常数， int &a不可以
    {
        this->value += a;
        cout << "调用了operator=(const int &a)" << endl;
    }
    Person &operator++(); //前置
    Person operator++(int)
    {
        Person temp = *this;  // 是调用拷贝函数
        this->value++;
        return temp;
        // Person temp;  temp = *this; 是调用operator=
    }
    void operator()(int a, int b) { cout << endl; this->value = this->value + a + b; cout << endl; }
    Person(Person &other)  // Person a = b    或   Person a(b)
    {
        this->value = other.value;
        other.next = this;
        cout << "调用了拷贝函数Person(Person &other)" << endl;
    }
    Person(int value=0) { this->value = value; }
}; 
ostream &operator<<(ostream &cout, Person p)  //全局函数重载法
{//返回引用是链式编程思想及  cout<<p<<endl;
    cout << p.value<<" "<<p.next<<" | "; //cout有很多重载的，我们调用的是其他的
    return cout;
}
Person &Person::operator++()
{
    ++value;
    return *this;
}
int main()
{
    Person a(95), b(96);
    cout << "a = " << a.value << " b= " << b.value << endl;
    a++;
    cout << "a = " << a.value << " b= " << b.value << endl;
    Person c = 5;  //调用默认构建函数
    c = 6;
    cout << c.value << endl;
    c(3, 4);
    // cout << c << endl;
    cout << c.value;
}


