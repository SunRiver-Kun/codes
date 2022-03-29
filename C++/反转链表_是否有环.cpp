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

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	bool hasCycle(ListNode* head) {
		ListNode* lastnode = NULL, * node = head, * temp;
		while (node)
		{
			temp = node;
			node = node->next;
			temp->next = lastnode;
			lastnode = temp;
			if (node == head) { return true; }
		}
		return false;
	}
};

int main()
{
}