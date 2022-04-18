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
int singlePointerParition(int arr[], int left, int right)//�˴�left��rightָ���ڴ���������εĵ�һ��Ԫ�������һ��Ԫ�ص��±�
{
	int i = left;
	int mark = arr[right];					//����right�±���ָԪ��Ϊ�ָ�Ԫ��
	for (int j = left; j <= right; j++)		//������Χ������Ԫ��
	{
		if (arr[j] < mark)					
		{
			swap(arr, i, j);				//���±�j��ָԪ��С�ڷָ�Ԫ�أ��򽫸�Ԫ����i�±���ָԪ�ؽ��н���
			i++;	
		}
	}
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
	/*�㷨���ģ����±�j��ָԪ��С�ڷָ�Ԫ�أ��򽫸�Ԫ����i�±���ָԪ�ؽ��н��������±�j��ָԪ�ز�С�ڷָ�Ԫ�أ������Ԫ�ز�����j����ƽ��������Ϳ��԰�
	�ȷָ�Ԫ��С��Ԫ�طŵ������ǰ���������Ԫ�طŵ�����󲿡�

	ѧϰ��ʱ����һ�����ʣ������͸�ȷ��i�±�Ԫ���Ǵ��ڵ���j�±�Ԫ�ص��أ����С���˲������ˣ����͵���ǰ���нϴ�Ԫ������
	˼����ó����ǣ�i�±�Ԫ�رض����ڵ���j�±�Ԫ�ء�i��j����left��ʼ��ֻ��jԪ�ط�����С�ڷָ�Ԫ�ص������i�Ż�����ƽ�һ�£���͵���i�ض�С��j����ʱ
	��iԪ���Ѿ�������ָ�Ԫ�صĴ�С�жϲ���û�н��н�����Ҳ��˵��iԪ��һ�����ڷָ�Ԫ�أ���һ������jԪ�أ�*/
	/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/


	swap(arr, i, right);					//���ָ�Ԫ�أ���right��ָԪ�أ���iԪ�ؽ���������i���󣨰���i����Ԫ�ؾ����ڵ��ڷָ�Ԫ��
											//!!!!!!!!!!�ò�����������!!!!!!!!!!!!
	return i;
}

/*
���ܣ���ָ�뷨��������
arr������
left����Χ�����±�
right����Χ�����±�
*/
void singlePointerQuickSort(int arr[], int left, int right)
{
	if (left >= right)						//�ݹ�߽���������Χ�ڽ���һ��Ԫ��ʱ����������������ˣ�Ҳ��ζ�������Ѿ���ɣ�ֹͣ�ݹ�
	{
		return;
	}

	int paritionMark = singlePointerParition(arr, left, right);	//�õ��ָ�Ԫ�ص��±�

	singlePointerQuickSort(arr, left, paritionMark - 1);			//�ݹ�����ǰ����С�ڷָ�Ԫ�صĲ��֣�������������Ƿָ������һ����Ȼ�����޵ݹ�
	singlePointerQuickSort(arr, paritionMark+1, right);			//�ݹ�����󲿣����ڷָ�Ԫ�صĲ��֣�������������Ƿָ������һ����Ȼ�����޵ݹ�
}



