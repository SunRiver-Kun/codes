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
	//д��defalut��new A[size]{]ʱ�Ż��Զ����value��0
	A() noexcept = default;

	A(int value) noexcept : value(value) {};
	//����cout������д��friend
	friend ostream& operator<< (ostream& out, const A& a)
	{
		out << a.value;
		return out;
	}
};

int main()
{
	int n = 10;
	//ֵ���ͣ������Զ���ʼ��
	cout << "ֵ����" << endl;
	fn(new int);
	fn(new int(0));
	fn(new int[n], n);
	fn(new int[n] {}, n);
	//�࣬���Զ����ù��캯��
	cout << "��" << endl;
	fn(new A);
	fn(new A(0));
	fn(new A[n], n);
	fn(new A[n]{  }, n);

	//����������ָ�룬���Զ���ʼ��defalut
	//����ȫ��д��
	unique_ptr<int> a(new int);
	unique_ptr<int[]> arr(new int[10]);
	//unique_ptr<int> arr(new int[10>) �Ǵ���ģ�������ʱ����delete������delete[]
	//�Ƽ�

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