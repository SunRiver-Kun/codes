#include<iostream>
#include <functional>
using namespace std;
typedef bool (*Bfn)(int a, int b);  //º¯ÊýÖ¸Õë
bool IsBigger(int a, int b)
{
	return a > b;
}

void fun(int a, int b, Bfn fn)
{
	cout << boolalpha << fn(a, b) << endl;
}

template <typename T, typename _Func>
void Fn(const T& a, const T& b, _Func fn)
{
	cout << boolalpha << fn(a, b) << endl;
}

template <typename T>
void Fn2(T a, T b, std::function<bool(T, T)> fn)
{
	cout << boolalpha << fn(a, b) << endl;
}

int main()
{
	bool (*xxx)(int, int);
	xxx = IsBigger;
	fun(4, 5, xxx);
	fun(2, 1, IsBigger);
	Fn(4, 5, xxx);
	Fn2(2, 1, function(IsBigger));
	system("pause");
}