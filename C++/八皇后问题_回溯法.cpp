#include <iostream>
#include <vector>
#include <boost/progress.hpp>
using namespace std;

//八皇后问题：在8x8的格子里放8个皇后，使没有两个皇后在同一行、列、斜线
//回溯法
constexpr const int row = 8, col = 8, size_queens = 8;

//当前的摆放是否合理
bool IsLegal(const vector<pair<int, int>>& queens)
{
	if (queens.size() <= 1) { return true; }
	for (int i = 0; i < queens.size(); ++i)
	{
		auto target = queens[i];
		for (int j = i + 1; j < queens.size(); ++j)
		{
			if (target.first == queens[j].first || target.second == queens[j].second) { return false; }
			double k = double(queens[j].second - target.second) / double(queens[j].first - target.first);
			if (k == 1.0 || k == -1.0) { return false; }
		}
	}
	return true;
}

unsigned long long num = 0;

//如果记录有皇后的位置，IsLegal就可以去掉搜索遍历，EightQueens就可以减少递归次数
bool EightQueens(bool spot_taken[row][col], vector<pair<int, int>>& queens, int num_queens = 0)
{
	num++;

	if (!IsLegal(queens)) { return false; }
	if (num_queens == size_queens) { return true; }

	pair<int, int> newpos = queens.empty() ? make_pair(0, 0) : queens.back();

	for (int i = newpos.first; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (!spot_taken[i][j])	//这个位置是空的
			{
				spot_taken[i][j] = true;
				queens.push_back(make_pair(i, j));
				if (EightQueens(spot_taken, queens, num_queens + 1)) { return true; }
				spot_taken[i][j] = false;
				queens.pop_back();
			}
		}
	}

	return false;
}

int main()
{
	bool spot_taken[row][col]{};
	vector<pair<int, int>> queens;
	{
		boost::progress_timer t;
		EightQueens(spot_taken, queens);
	}
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << spot_taken[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl << "total calculate:" << num << endl;
	system("pause");
}