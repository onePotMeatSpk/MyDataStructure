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
int singlePointerParition(int arr[], int left, int right)//此处left与right指正在处理的数组段的第一个元素与最后一个元素的下标
{
	int i = left;
	int mark = arr[right];					//设置right下标所指元素为分隔元素
	for (int j = left; j <= right; j++)		//遍历范围内所有元素
	{
		if (arr[j] < mark)					
		{
			swap(arr, i, j);				//若下标j所指元素小于分隔元素，则将该元素与i下标所指元素进行交换
			i++;	
		}
	}
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*算法核心：若下标j所指元素小于分隔元素，则将该元素与i下标所指元素进行交换；若下标j所指元素不小于分个元素，则这个元素不动，j向后推进。这样就可以把
	比分隔元素小的元素放到数组的前部，而大的元素放到数组后部。

	学习的时候有一个疑问：怎样就敢确定i下标元素是大于等于j下标元素的呢，如果小于了并交换了，不就导致前部有较大元素了吗？
	思考后得出答案是：i下标元素必定大于等于j下标元素。i与j均从left开始，只有j元素发生了小于分隔元素的情况，i才会向后推进一下，这就导致i必定小于j，此时
	的i元素已经经过与分隔元素的大小判断并且没有进行交换，也就说明i元素一定大于分隔元素，则一定大于j元素！*/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


	swap(arr, i, right);					//将分隔元素（即right所指元素）与i元素交换，这样i往后（包括i）的元素均大于等于分隔元素
											//!!!!!!!!!!该操作不能遗忘!!!!!!!!!!!!
	return i;
}

/*
功能：单指针法快速排序
arr：数组
left：范围最左下标
right：范围最右下标
*/
void singlePointerQuickSort(int arr[], int left, int right)
{
	if (left >= right)						//递归边界条件：范围内仅有一个元素时，便无需进行排序了，也意味着排序已经完成，停止递归
	{
		return;
	}

	int paritionMark = singlePointerParition(arr, left, right);	//得到分隔元素的下标

	singlePointerQuickSort(arr, left, paritionMark - 1);			//递归数组前部（小于分隔元素的部分），右坐标必须是分隔坐标减一，不然会无限递归
	singlePointerQuickSort(arr, paritionMark+1, right);			//递归数组后部（大于分隔元素的部分），左坐标必须是分隔坐标加一，不然会无限递归
}




