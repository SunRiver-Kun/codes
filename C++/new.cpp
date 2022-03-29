#include <iostream>
#include <memory>
using namespace std;

template <typename _Ty>
void fn(_Ty* (&& ptr))
{
	cout << *ptr << endl;
	delete ptr;
}

template <typename _Ty>
void fn(_Ty* (&& arr), int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
	delete[] arr;
}

struct A
{
	int value;
	//写成defalut，new A[size]{]时才会自动帮把value置0
	A() noexcept = default;

	A(int value) noexcept : value(value) {};
	//可以cout，必须写成friend
	friend ostream& operator<< (ostream& out, const A& a)
	{
		out << a.value;
		return out;
	}
};

int main()
{
	int n = 10;
	//值类型，不会自动初始化
	cout << "值类型" << endl;
	fn(new int);
	fn(new int(0));
	fn(new int[n], n);
	fn(new int[n] {}, n);
	//类，会自动调用构造函数
	cout << "类" << endl;
	fn(new A);
	fn(new A(0));
	fn(new A[n], n);
	fn(new A[n]{  }, n);

	//下面是智能指针，会自动初始化defalut
	//不安全的写法
	unique_ptr<int> a(new int);
	unique_ptr<int[]> arr(new int[10]);
	//unique_ptr<int> arr(new int[10>) 是错误的，析构的时候是delete而不是delete[]
	//推荐

	auto u = make_unique<int>();
	cout << "make_unique<int>()" << *u << endl;

	auto uu = make_unique<int[]>(n);
	cout << "make_unique<int[]>(n)\n";
	for (int i = 0; i < n; ++i)
	{
		cout << uu[i] << ' ';
	}
	cout << endl;

	system("pause");
}