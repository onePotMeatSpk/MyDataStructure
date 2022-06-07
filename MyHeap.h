#pragma once
#include<vector>
#include<iostream>
using namespace std;

class MyHeap
{
private:
	vector<int> nums;
	bool flagMaxMin;

public:
	MyHeap(bool flag) :flagMaxMin(flag) {}

	void push(int num)
	{
		nums.push_back(num);
		pushHeap(nums.size() - 1);
	}

	void pop()
	{
		popHeap(nums.size());
		nums.pop_back();
	}

	int top()
	{
		if (nums.empty())	return INT_MIN;
		return nums[0];
	}

	void sort()
	{
		sortHeap();
	}

	int size()
	{
		return nums.size();
	}

	void print()
	{
		for (int i = 0; i < nums.size(); i++)
			cout << nums[i] << " ";
		cout << endl;
	}


private:
	void pushHeap(int hole)
	{
		int val2Push = nums[hole];
		int parent = (hole - 1) / 2;

		while (hole > 0 && (flagMaxMin ? val2Push > nums[parent] : val2Push < nums[parent]))
		{
			nums[hole] = nums[parent];
			hole = parent;
			parent = (hole - 1) / 2;
		}

		nums[hole] = val2Push;
	}

	void popHeap(int len)
	{
		int hole = 0;
		int val2Pop = nums[hole];
		int secondChild = hole * 2 + 2;

		while (secondChild < len)
		{
			if (flagMaxMin ? nums[secondChild - 1] > nums[secondChild] : nums[secondChild - 1] < nums[secondChild])	secondChild--;

			nums[hole] = nums[secondChild];
			hole = secondChild;
			secondChild = hole * 2 + 2;
		}

		if (secondChild == len)
		{
			secondChild--;
			nums[hole] = nums[secondChild];
			hole = secondChild;
		}

		swap(nums[hole], nums[len - 1]);
		nums[len - 1] = val2Pop;

		if (hole != len - 1)	pushHeap(hole);
	}

	void sortHeap()
	{
		int len = nums.size();
		while (len)
			popHeap(len--);
	}
};