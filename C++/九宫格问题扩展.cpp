//九宫格问题扩展，行、列、对角之和相等
//一居上行正中央，依次斜填切莫忘；上出框时向下放，右出框时向左放；排重便在下格填，右上排重一个样。
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argn, char* argv[])
{
	cout << "请输入矩阵的大小：";
	int n;
	cin >> n;
	//构建二维矩阵，其实用vector也可以
	int** matrix = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		matrix[i] = new int[n] {};
	}
	//赋值
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

	//输出
	cout << left;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
	//销毁矩阵
	for (int i = n - 1; i >= 0; --i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
	system("pause");
}