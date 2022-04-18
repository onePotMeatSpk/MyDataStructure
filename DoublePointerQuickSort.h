#pragma once
#include<iostream>
#include<string>
#include"Swap.h"

using namespace std;


/*
���ܣ���arr������±�left��right������left��right��֮��Ĳ��ֻ���Ϊ������
���أ��������ֵķָ��±꣬�ָ��±�����±���ָԪ��С�ڷָ��±���ָԪ�أ��ұߴ���
arr������
left����Χ�����±�
right����Χ�����±�
*/
int doublePointerParition(int arr[], int left, int right)//�˴�left��rightָ���ڴ��������εĵ�һ��Ԫ�������һ��Ԫ�ص��±�
{
	int i = left;
	int j = right;
	int mark = arr[left];
	while (i != j)
	{
		/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
		/*�㷨���ģ��˴�����j���߶���i���ߵ�ԭ���ǣ�j��ͣ���ط���ֵһ����С�ڷָ�ֵ�ģ��ȴ��ұ��ߵĻ������Ա�֤�����i��j����
		ʱ����������ֵҲһ����С�ڷָ�ֵ�ģ��������Ա�֤���left��i��ֵ������leftֵһ��С�ڷָ�ֵ��
		��Ҫע�����ǣ���������ѡ��left���ָ�ֵ���ʶ��ȴ����ߣ�����ѡ��right���ָ�ֵ��Ӧ���ȴ����ߣ��Ա�֤��󽻻����rightһ��
		���ڷָ�ֵ��     Ҳ����˵��������Σ�Ӧ���ӷָ�ֵ�Ķ������ߡ�*/
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
���ܣ�˫ָ�뷨��������
arr������
left����Χ�����±�
right����Χ�����±�
*/
void doublePointerQuickSort(int arr[], int left, int right)
{
	if (left >= right)						//�ݹ�߽���������Χ�ڽ���һ��Ԫ��ʱ����������������ˣ�Ҳ��ζ�������Ѿ���ɣ�ֹͣ�ݹ�
	{
		return;
	}

	int paritionMark = doublePointerParition(arr, left, right);	//�õ��ָ�Ԫ�ص��±�

	doublePointerQuickSort(arr, left, paritionMark - 1);			//�ݹ�����ǰ����С�ڷָ�Ԫ�صĲ��֣�������������Ƿָ������һ����Ȼ�����޵ݹ�
	doublePointerQuickSort(arr, paritionMark + 1, right);			//�ݹ�����󲿣����ڷָ�Ԫ�صĲ��֣�������������Ƿָ������һ����Ȼ�����޵ݹ�
}
