#include<iostream>
using namespace std;
/*�ܽ�
1. operator@ ʵ���Ǻ�������, a + b <--> a.operator(b)
2. Person a = ... //����ù�������
3. a = ...  //��ʱ���ǵ���operator=
4.const int &a  ���� const int a ���� int a ����ֱ�Ӽӳ����� int &a������

*/

class Person
{
public:
    int value;
    Person *next=NULL;
    //��������ر��ʻ��Ǻ�������
    Person operator+(Person &other)   //a+b  <--> a.operator+(b);
    {
        cout << "���������������+" << endl;
        this->value += other.value;
        return *this;
    }
    void operator=(Person &other)  //���Ա�������ط�  a=b <--> a.operator(b)
    {
        this->value = other.value;
        this->next = other.next;  //ǳ����
        cout << "���������������=" << endl;
    }
    void operator=( int a)  //const int &a  ���� const int a ���� int a ����ֱ�Ӽӳ����� int &a������
    {
        this->value += a;
        cout << "������operator=(const int &a)" << endl;
    }
    Person &operator++(); //ǰ��
    Person operator++(int)
    {
        Person temp = *this;  // �ǵ��ÿ�������
        this->value++;
        return temp;
        // Person temp;  temp = *this; �ǵ���operator=
    }
    void operator()(int a, int b) { cout << endl; this->value = this->value + a + b; cout << endl; }
    Person(Person &other)  // Person a = b    ��   Person a(b)
    {
        this->value = other.value;
        other.next = this;
        cout << "�����˿�������Person(Person &other)" << endl;
    }
    Person(int value=0) { this->value = value; }
}; 
ostream &operator<<(ostream &cout, Person p)  //ȫ�ֺ������ط�
{//������������ʽ���˼�뼰  cout<<p<<endl;
    cout << p.value<<" "<<p.next<<" | "; //cout�кܶ����صģ����ǵ��õ���������
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
    Person c = 5;  //����Ĭ�Ϲ�������
    c = 6;
    cout << c.value << endl;
    c(3, 4);
    // cout << c << endl;
    cout << c.value;
}


