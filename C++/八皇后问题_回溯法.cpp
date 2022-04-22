#include <iostream>
#include <vector>
using namespace std;

//判断个数
class Solution
{
public:
	/**
	 *
	 * @param n int整型 the n
	 * @return int整型
	 */
	int col = 8, size_queens = 8;

	int Nqueen(int n)
	{
		// write code here
		col = size_queens = n; //仅仅方便判断减少
		vector<vector<bool>> spot_taken(n, vector<bool>(n, false));
		vector<pair<int, int>> queens;
		return EightQueens(spot_taken, queens);
	}

	//当前的摆放是否合理
	bool IsLegal(const vector<pair<int, int>> &queens)
	{
		if (queens.size() <= 1)
		{
			return true;
		}
		for (int i = 0; i < queens.size(); ++i)
		{
			const auto &target = queens[i];
			for (int j = i + 1; j < queens.size(); ++j)
			{
				if (target.first == queens[j].first || target.second == queens[j].second)
				{
					return false;
				}
				float k = float(queens[j].second - target.second) / float(
																		queens[j].first - target.first);
				if (abs(k - 1) < 1E-5 || abs(k + 1) < 1E-5)
				{
					return false;
				}
			}
		}
		return true;
	}

	//如果记录有皇后的位置，IsLegal就可以去掉搜索遍历，EightQueens就可以减少递归次数
	int EightQueens(vector<vector<bool>> &spot_taken,
					vector<pair<int, int>> &queens,
					int num_queens = 0)
	{
		if (!IsLegal(queens))
		{
			return 0;
		}
		if (num_queens == size_queens)
		{
			return 1;
		}

		int i = queens.empty() ? 0 : queens.back().first + 1;
		int num = 0;
		for (int j = 0; j < col; ++j)
		{
			spot_taken[i][j] = true;
			queens.push_back(make_pair(i, j));
			num += EightQueens(spot_taken, queens, num_queens + 1);
			spot_taken[i][j] = false;
			queens.pop_back();
		}

		return num;
	}
};


//仅仅是为了打印第一个图
//八皇后问题：在8x8的格子里放8个皇后，使没有两个皇后在同一行、列、斜线
//回溯法
constexpr const int row = 8, col = 8, size_queens = 8;

//当前的摆放是否合理
bool IsLegal(const vector<pair<int, int>> &queens)
{
	if (queens.size() <= 1)
	{
		return true;
	}
	for (int i = 0; i < queens.size(); ++i)
	{
		const auto &target = queens[i];
		for (int j = i + 1; j < queens.size(); ++j)
		{
			if (target.first == queens[j].first || target.second == queens[j].second)
			{
				return false;
			}
			float k = float(queens[j].second - target.second) / float(
																	queens[j].first - target.first);
			if (abs(k - 1) < 1E-5 || abs(k + 1) < 1E-5)
			{
				return false;
			}
		}
	}
	return true;
}

//如果记录有皇后的位置，IsLegal就可以去掉搜索遍历，EightQueens就可以减少递归次数
bool EightQueens(bool spot_taken[row][col], vector<pair<int, int>> &queens, int num_queens = 0)
{
	if (!IsLegal(queens))
	{
		return false;
	}
	if (num_queens == size_queens)
	{
		return true;
	}

	pair<int, int> newpos = queens.empty() ? make_pair(0, 0) : queens.back();

	int i = queens.empty() ? 0 : queens.back().first + 1;
	for (int j = 0; j < col; ++j)
	{

		spot_taken[i][j] = true;
		queens.push_back(make_pair(i, j));
		if (EightQueens(spot_taken, queens, num_queens + 1))
		{
			return true;
		}
		spot_taken[i][j] = false;
		queens.pop_back();
	}

	return false;
}

int main()
{
	bool spot_taken[row][col]{};
	vector<pair<int, int>> queens;
	EightQueens(spot_taken, queens);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << spot_taken[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
}

