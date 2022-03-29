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
	 * �����е����������������������Ѿ�ָ���������޸ģ�ֱ�ӷ��ط����涨��ֵ����
	 *
	 * ���Ŀ��ֵ���ڷ����±꣬���򷵻� -1
	 * @param nums int����vector
	 * @param target int����
	 * @return int����
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