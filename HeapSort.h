#pragma once
#include<iostream>
#include<string>
using namespace std;

//https://aijishu.com/a/1060000000090217为讲述堆排序较清楚的帖子
void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}

void adjustHeap(int arr[], int arrLength, int index)
{
	int lchild = index * 2 + 1;
	int rchild = index * 2 + 2;
	int maxIndex = index;

	if ((lchild < arrLength) && (arr[lchild] > arr[maxIndex]))
	{
		maxIndex = lchild;
	}
	if ((rchild < arrLength) && (arr[rchild] > arr[maxIndex]))
	{
		maxIndex = rchild;
	}

	if (maxIndex != index)
	{
		swap(arr, maxIndex, index);
		adjustHeap(arr, arrLength, maxIndex);
	}
}

void heapSort(int arr[], int arrLength)
{
	for (int i = (arrLength / 2) - 1; i >= 0; i--)
	{
		adjustHeap(arr, arrLength, i);
	}

	for (int i = arrLength - 1; i >= 1; i--)
	{
		swap(arr, 0, i);
		adjustHeap(arr, i, 0);
	}
}