#pragma once

/*
���ܣ�����arr�������±�Ϊindex1��index2������Ԫ��
arr������
index1����һ��Ԫ���±�
index2���ڶ���Ԫ���±�
*/
void swap(int arr[], int index1, int index2)
{
	int temp = arr[index1];
	arr[index1] = arr[index2];
	arr[index2] = temp;
}