#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

//∂—≈≈–Ú
void MakeHeap(vector<int>& arr)
{
	int index = 0;
	for (int i = 0; i < arr.size(); ++i)
	{
		index = i;
		while (index)
		{
			int parent = (index - 1) / 2;
			if (arr[index] <= arr[parent]) { break; }
			swap(arr[index], arr[parent]);
			index = parent;
		}
	}
}

int RemoveHeapTopItem(vector<int>& arr, int size)
{
	int result = arr[0];
	arr[0] = arr[size - 1];

	int index = 0;
	while (true)
	{
		int leftchild = 2 * index + 1;
		int rightchild = 2 * index + 2;
		if (leftchild >= size) { leftchild = index; }
		if (rightchild >= size) { rightchild = index; }

		if (arr[index] >= arr[leftchild] && arr[index] >= arr[rightchild]) { break; }

		int swap_child = arr[leftchild] > arr[rightchild] ? leftchild : rightchild;
		swap(arr[index], arr[swap_child]);

		index = swap_child;
	}
	return result;
}

void HeapSort(vector<int>& arr)
{
	MakeHeap(arr);
	for (int i = arr.size() - 1; i >= 0; --i)
	{
		int maxvalue = RemoveHeapTopItem(arr, i + 1);
		arr[i] = maxvalue;
	}
}

int main()
{
	vector<int> arr{ 5,48,67,13,4,0,15,3,0,-1,48,123 };
	HeapSort(arr);
	for (auto& v : arr)
	{
		cout << v << endl;
	}
	system("pause");
}