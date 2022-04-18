#pragma once
#include<iostream>
#include<string>
#include"Swap.h"

using namespace std;


/*
功能：将arr数组从下标left至right（包含left和right）之间的部分划分为两部分
返回：这两部分的分隔下标，分隔下标左边下标所指元素小于分隔下标所指元素，右边大于
arr：数组
left：范围最左下标
right：范围最右下标
*/
int doublePointerParition(int arr[], int left, int right)//此处left与right指正在处理的数组段的第一个元素与最后一个元素的下标
{
	int i = left;
	int j = right;
	int mark = arr[left];
	while (i != j)
	{
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
		/*算法核心：此处必须j先走而非i先走的原因是，j所停留地方的值一定是小于分隔值的，先从右边走的话，可以保证在最后i与j相遇
		时，相遇处的值也一定是小于分隔值的，这样可以保证最后left与i处值交换后，left值一定小于分隔值。
		需要注明的是：这里由于选择left当分隔值，故而先从右走；若是选择right当分隔值，应当先从左走，以保证最后交换后的right一定
		大于分隔值。     也就是说，不论如何，应当从分隔值的对面先走。*/
		while ((arr[j] >= mark) && (i < j))
		{
			j--;
		}

		while ((arr[i] <= mark) && (i < j))
		{
			i++;
		}

		swap(arr, i, j);	
	}


		swap(arr, left, i);

	return i;
}

/*
功能：双指针法快速排序
arr：数组
left：范围最左下标
right：范围最右下标
*/
void doublePointerQuickSort(int arr[], int left, int right)
{
	if (left >= right)						//递归边界条件：范围内仅有一个元素时，便无需进行排序了，也意味着排序已经完成，停止递归
	{
		return;
	}

	int paritionMark = doublePointerParition(arr, left, right);	//得到分隔元素的下标

	doublePointerQuickSort(arr, left, paritionMark - 1);			//递归数组前部（小于分隔元素的部分），右坐标必须是分隔坐标减一，不然会无限递归
	doublePointerQuickSort(arr, paritionMark + 1, right);			//递归数组后部（大于分隔元素的部分），左坐标必须是分隔坐标加一，不然会无限递归
}
