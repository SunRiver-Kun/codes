#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <vector>
#include <memory>


//稳定：插冒归基
//不稳定：快选堆希
namespace sr
{
#pragma region 插入排序
	//直接插入排序
	template <typename _Ty>
	void insert_sort(std::vector<_Ty>& arr)
	{
		for (int i = 1; i < arr.size(); ++i)
		{
			auto target = arr[i];
			int j = i;
			while (j > 0 && arr[j - 1] > target)
			{
				arr[j] = arr[j - 1];
				--j;
			}
			arr[j] = target;
		}
	}
	//二分插入排序 O(nlogn)
	template <typename _Ty>
	void binary_insert_sort(std::vector<_Ty>& arr)
	{
		int left, right, middle;
		for (int i = 1; i < arr.size(); ++i)
		{
			auto target = arr[i];
			left = 0;
			right = i - 1;
			while (left <= right)
			{
				middle = (left + right) / 2;
				if (arr[middle] < target)
					left = middle + 1;
				else
					right = middle - 1;
			}
			for (int j = i; j > left; --j) { arr[j] = arr[j - 1]; }
			arr[left] = target;
		}
	}
	//希尔排序：间隔渐小的插入排序，不稳定
	template <typename _Ty>
	void shell_sort(std::vector<_Ty>& arr)
	{
		int gap = arr.size() / 2;	//间隔
		while (gap)
		{
			for (int i = gap; i < arr.size(); ++i)
			{
				auto target = arr[i];
				int j = i;
				while (j >= gap && arr[j - gap] > target)
				{
					arr[j] = arr[j - gap];
					j -= gap;
				}
				arr[j] = target;
			}
			gap = gap / 2;
		}
	}
#pragma endregion

#pragma region 选择排序
	//冒泡排序 O(n2)
	template <typename _Ty>
	void bubble_sort(std::vector<_Ty>& arr)
	{
		for (int i = 0; i < arr.size(); ++i)
		{
			for (int j = i + 1; j < arr.size(); ++j)
			{
				if (arr[i] > arr[j])
					std::swap(arr[i], arr[j]);
			}
		}
	}

	//鸡尾酒排序（Shaker，双向冒泡排序）	在基本有序下是O(n)，其他为O(n2)
	template <typename _Ty>
	void shaker_sort(std::vector<_Ty>& arr)
	{
		int  left = 0, right = arr.size() - 1, shift = 0;
		while (left < right)
		{
			for (int i = left; i < right; ++i)	//向右进行冒泡排序
			{
				if (arr[i] > arr[i + 1])
				{
					std::swap(arr[i], arr[i + 1]);
					shift = i;	//记录最后一次所在的位置
				}
			}
			right = shift;

			for (int i = right; i > left; --i)	//向左进行冒泡排序
			{
				if (arr[i] < arr[i - 1])
				{
					std::swap(arr[i], arr[i - 1]);
					shift = i;
				}
			}
			left = shift;
		}
	}

	//快速排序	O(nlogn)-O(n2)，不稳定
	template <typename _Ty>
	void __QuickSort(std::vector<_Ty>& arr, int left, int right)
	{
		if (left>=right) { return; }

		int i = left, j = right;
		auto base = arr[left];
		while (i < j)
		{
			//从右向左找比基数小的元素
			while (i < j && arr[j] >= base) { --j; }
			arr[i] = arr[j];

			//从左向右找比基数大的元素
			while (i < j && arr[i] <= base) { ++i; }
			arr[j] = arr[i];
		}
		arr[i] = base;	//i==j

		__QuickSort(arr, left, i - 1);
		__QuickSort(arr, i + 1, right);
	}
	template <typename _Ty>
	void quick_sort(std::vector<_Ty>& arr)
	{
		__QuickSort(arr, 0, arr.size() - 1);
	}

	//堆：父节点大于等于所有子结点		O(nlogn)
	template <typename _Ty>
	void __MakeHeap(std::vector<_Ty>& arr)
	{
		int index = 0;
		for (int i = 0; i < arr.size(); ++i)
		{
			index = i;
			while (index)
			{
				int parent = (index - 1) / 2;
				if (arr[index] <= arr[parent]) { break; }
				std::swap(arr[index], arr[parent]);
				index = parent;
			}
		}
	}
	template <typename _Ty>
	_Ty __RemoveHeapTopItem(std::vector<_Ty>& arr, int size)
	{
		auto result = arr[0];
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
			std::swap(arr[index], arr[swap_child]);

			index = swap_child;
		}
		return result;
	}
	template <typename _Ty>
	void heap_sort(std::vector<_Ty>& arr)
	{
		__MakeHeap(arr);
		for (int i = arr.size() - 1; i >= 0; --i)
		{
			auto maxvalue = __RemoveHeapTopItem(arr, i + 1);
			arr[i] = maxvalue;
		}
	}
#pragma endregion

#pragma region 其他排序
	//归并排序 O(nlogn)
	template <typename _Ty>
	void __Merge(std::vector<_Ty>& arr, std::vector<_Ty>& temp, int left, const int center, int right)
	{
		int index = left;
		int left_first = left;
		int right_first = center + 1;
		while (left_first <= center && right_first <= right)
		{
			if (arr[left_first] < arr[right_first])
			{
				temp[index++] = arr[left_first++];
			}
			else
			{
				temp[index++] = arr[right_first++];
			}
		}
		while (left_first <= center)
		{
			temp[index++] = arr[left_first++];
		}
		while (right_first <= right)
		{
			temp[index++] = arr[right_first++];
		}
		while (left <= right)
		{
			arr[left] = temp[left];
			++left;
		}
	}

	template <typename _Ty>
	void __MergeSort(std::vector<_Ty>& arr, std::vector<_Ty>& temp, int left, int right)
	{
		if (left >= right) { return; }
		int center = (left + right) / 2;
		__MergeSort(arr, temp, left, center);
		__MergeSort(arr, temp, 1 + center, right);
		__Merge(arr, temp, left, center, right);
	}

	template <typename _Ty>
	void merge_sort(std::vector<_Ty>& arr)
	{
		if (arr.size() <= 1) { return; }
		std::vector<_Ty> temp(arr.size());
		__MergeSort(arr, temp, 0, arr.size() - 1);
	}
	//计数排序
	template <typename _Ty>
	void count_sort(std::vector<_Ty>& arr)
	{
		const auto it_minmax = std::minmax_element(arr.begin(), arr.end());
		auto value = *it_minmax.first;
		size_t size = *it_minmax.second - *it_minmax.first + 1;
		auto counter = std::make_unique<int[]>(size);

		for (auto& v : arr)
		{
			counter[v - value] += 1;
		}

		auto it = arr.begin();
		for (int i = 0; i < size; ++i)
		{
			for (int j = 0; j < counter[i]; ++j)
			{
				*it++ = value;
			}
			++value;
		}
	}

	//基数排序，按个十百等位把数放到0-9的桶里，反复直到都在0桶里
#pragma endregion
}
