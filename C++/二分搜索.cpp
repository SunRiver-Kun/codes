#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
	/**
	 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
	 *
	 * 如果目标值存在返回下标，否则返回 -1
	 * @param nums int整型vector
	 * @param target int整型
	 * @return int整型
	 */
	int search(vector<int>& nums, int target) {
		int left = 0, right = static_cast<int>(nums.size()) - 1;
		while (left <= right)
		{
			int mid = (left + right) / 2;
			auto&& value = nums[mid];
			if (value > target)
			{
				right = mid - 1;
			}
			else if (value == target)
			{
				return mid;
			}
			else
			{
				left = mid + 1;
			}
		}
		return -1;
	}
};

int main()
{
}