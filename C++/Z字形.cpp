//Z����
//�Խ��� = 2*x*x + 2*x   x����[0,n-1]
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argn, char* argv[])
{
	cout << "���������Ĵ�С��";
	int n;
	cin >> n;
	//������ά������ʵ��vectorҲ����
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n] {};
	}
	//��ֵ
	int i = 0, j = 0;
	for (int value = 0; value < n * n; ++value)
	{
		matrix[i][j] = value;
		//��
		if ((i == 0 || i == n - 1) && j % 2 == 0)
		{
			++j;
			continue;
		}
		//��
		if ((j == 0 || j == n - 1) && i % 2)
		{
			++i;
			continue;
		}
		//�L
		if ((i + j) % 2)
		{
			++i;
			--j;
		}
		//�J
		else
		{
			--i;
			++j;
		}
	}
	//���
	cout << left;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
	//���پ���
	for (int i = n - 1; i >= 0; --i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	system("pause");
}