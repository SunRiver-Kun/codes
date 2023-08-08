//�Ź���������չ���С��С��Խ�֮�����
//һ�����������룬����б����Ī�����ϳ���ʱ���·ţ��ҳ���ʱ����ţ����ر����¸����������һ������
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
	int row = 0, col = n / 2;
	for (int i = 1; i <= n * n; ++i)
	{
		matrix[row][col] = i;
		--row;
		++col;

		if (row < 0 && col >= n)
		{
			--col;
			row += 2;
		}
		else if (row < 0)
		{
			row = n - 1;
		}
		else if (col >= n)
		{
			col = 0;
		}
		else if (matrix[row][col])
		{
			--col;
			row += 2;
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