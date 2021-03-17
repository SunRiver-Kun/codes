/*!
省略参数...
的使用方法
#include<cstdarg> 
va_arg类型不能是指针,必须有个循环结束标志

方法2：
#include<initializer_list>
std::initializer_list
for (const auto &each : list)

方法3：
利用aggregate class 的条件  <-->  其实和struct差不多
所有的非常量数据成员都是公有的
没有定义任何构建函数（但可以使用=default或=delete）
没有基类
没有虚函数成员
没有类内初始化（c++14后废除）
方法4：
有构造函数,不够构造函数不能有数组参数
Std stds[2]={ {"w",1},{"y",2}  }
*/
#include<iostream>
#include<cstdarg>
#include<initializer_list>
using namespace std;
int add(int i,...)  //省略参数前面必须有个固定参数,add(...)是错误的
{
    va_list list;
    int sum = i,value;
    va_start(list,i);  //i为之前的参数
    do
    {
        value = va_arg(list,int);
        sum += value;
    } while (value!=0);
    va_end(list);
    cout << sum << endl;
    return sum;
}
class A
{
public:
    int num;
    int score[10];
    A(int num = 0) { this->num = num; };
    int add(A a,...)
    {
        va_list list;
        A i;
        this->num += a.num;
        va_start(list,a);
        do
        {
            i = va_arg(list,A);
            this->num += i.num;
        } while (i.num!=0);
        va_end(list);
        return this->num;
    }

};

class Mymatrix
{
private:
    int row;
    int col;
    double *data;
public:
    Mymatrix(int row,int col) :row(row),col(col) { data = new double[row*col]; }
    Mymatrix(int row,int col,std::initializer_list<double>list) :Mymatrix(row,col) 
    {  
        std::size_t i = 0;
        for (const auto &each : list)
            data[i++] = each;
    }
    Mymatrix() { delete[]data; }
    Mymatrix &operator=(std::initializer_list<double>list)
    {
        std::size_t i = 0;
        for (const auto &each : list) //不能随便用...
            data[i++] = each;
        return *this;
    }
    double get(int r,int c) const{ return data[r*row+c]; }
};
class Mymatrix2
{
public:
    int row;
    int col;
    double data[10];
};
int main()
{
    //add(1,0);
    //add(1,2,0);
    //add(1,2,3,0);

    //A x,y(1),z(2);
    //cout << x.add(y,z,A()) << " " << x.num<<" ";
    //cout << x.num << endl;
    //Mymatrix m1(3,3);
    //m1 = {
    //    1,2,3,
    //    4,5,6,
    //    7,8,9
    //};
    //cout << m1.get(0,0) << endl;
    //Mymatrix m2(3,3,{
    //    1,2,3,
    //    4,5,6,
    //    7,8,9 });
    //cout << m2.get(1,1)<<endl;

    //Mymatrix2 m3 = { 3,4,{1,2,3,4,5,6} };
    //cout << m3.data[4] << endl;
}
