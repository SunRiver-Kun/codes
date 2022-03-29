#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
    Person(const string name = "", const int age = 0)
    {
        this->name = name;
        this->age = age;
    }
    int GetAge();
    string GetName();
protected:
    int age;
    string name;

    //friend ÈÓÄÄÀï¶¼ÐÐ
    friend Person GetPerson(const Person& other);
};
class Parent :public Person
{
public:
    Parent(const string name = "", const int age = 0, const string job="") :Person(name, age)
    {
        this->job = job;
    }
private:
    string job;

    friend class Son;
};

class Son:public Person
{
public:
    Son(const string name = "", const int age = 0, const Parent *parent = NULL) :Person(name, age)
    {
        this->parent = parent;
    }
    string GetParentJob();
private:
    const Parent *parent;
};
int main()
{
    Parent father("Tom", 58, "teacher");
    Son son("Jack", 20, &father);
    cout << son.GetParentJob() << endl;
}

Person GetPerson(const Person &other)
{
    return Person(other.name, other.age);
}

int Person::GetAge()
{
    return age;
}

string Person::GetName()
{
    return name;
}

string Son::GetParentJob()
{
    return parent->job;
}
