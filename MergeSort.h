#pragma once
#include<iostream>
#include<string>

using namespace std;

void merge(int arr[], int left, int right, int mid)
{
	int* arrTemp = new int[right - left + 1];
	int leftPoniter = left;
	int rightPointer = mid + 1;
	int i = 0;
	while ((leftPoniter <= mid) && (rightPointer <= right))
	{
		arrTemp[i] = arr[leftPoniter] <= arr[rightPointer] ? arr[leftPoniter++] : arr[rightPointer++];
		i++;
	}

	while (leftPoniter <= mid)
	{
		arrTemp[i] = arr[leftPoniter++];
		i++;
	}

	while (rightPointer <= right)
	{
		arrTemp[i] = arr[rightPointer++];
		i++;
	}

	i = 0;
	while (i < right - left + 1)
	{
		arr[left + i] = arrTemp[i];
		i++;
	}

	delete arrTemp;
}


void mergeSort(int arr[], int left, int right)
{
	if (left == right)
	{
		return;
	}

	int mid = (left + right) / 2;
	mergeSort(arr, left, mid);
	mergeSort(arr, mid + 1, right);
	merge(arr, left, right, mid);
}