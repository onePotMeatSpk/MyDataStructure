#pragma once

/*
功能：交换arr数组中下标为index1与index2的两个元素
arr：数组
index1：第一个元素下标
index2：第二个元素下标
*/
void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}