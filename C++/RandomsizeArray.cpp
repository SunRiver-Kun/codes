#include <iostream>
using namespace std;

void RandomsizeArray(string arr[], int size)
{
	int max_i = size - 1;
	for (int i = 0; i < max_i; ++i)
	{
		int j = rand() % (max_i - i + 1) + i;
		arr[i].swap(arr[j]);
	}
}

int main()
{
	srand((size_t)time(NULL));
	string arr[] = { "A","B","C","D","E","F","G","H" };
	RandomsizeArray(arr, 8);
	for (auto& v : arr)
	{
		cout << v << endl;
	}
	system("pause");
}