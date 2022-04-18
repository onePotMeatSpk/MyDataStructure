#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray
{
public:

	myArray(int capInput);

	myArray(const myArray& myarray);

	myArray& operator= (const myArray& myarray);

	T& operator [] (const int index);

	~myArray();

	void pushBack(const T elementPushBack);

	void deleteBack();

	int getNum();

	int getCap();

	void print();

private:
	int num;//the number of elements in this class
	int cap;//the capacity of this class
	T* ptrStart;
};

template<class T>
myArray<T>::myArray(int capInput) : num(0), cap(capInput)
{
	this->ptrStart = new T[this->cap];

	for (int i = 0; i < cap; i++)
	{
		ptrStart[i] = 0;
	}
}

template<class T>
myArray<T>::myArray(const myArray& myarray) : num(myarray.num), cap(myarray.cap)
{
	this->ptrStart = new T[this->cap];

	for (int i = 0; i < cap; i++)
	{
		ptrStart[i] = myarray.ptrStart[i];
	}
}

template<class T>
myArray<T>& myArray<T>::operator=(const myArray& myarray)
{
	this->num = myarray.num;
	this->cap = myarray.cap;
	this->ptrStart = new T[this->cap];

	for (int i = 0; i < cap; i++)
	{
		ptrStart[i] = myarray.ptrStart[i];
	}

	return *this;
	// TODO: 在此处插入 return 语句
}



template<class T>
inline T& myArray<T>::operator [](const int index)
{
	return this->ptrStart[index];
	// TODO: 在此处插入 return 语句
}

template<class T>
myArray<T>::~myArray()
{
	if (this->ptrStart != NULL)
	{
		delete[] this->ptrStart;
		this->ptrStart = NULL;
		this->num = 0;
		this->cap = 0;
	}
}

template<class T>
void myArray<T>::pushBack(const T elementPushBack)
{
	if (this->num >= this->cap)
	{
		cout << "This Array has been filled completely!" << endl;
	}
	else
	{
		this->ptrStart[num] = elementPushBack;
		num++;
	}
}

template<class T>
void myArray<T>::deleteBack()
{
	if (num == 0)
	{
		cout << "This array has been emptied completely!";
	}
	else
	{
		this->ptrStart[num-1] = 0;
		num--;
	}
}

template<class T>
inline int myArray<T>::getNum()
{
	return this->num;
}

template<class T>
inline int myArray<T>::getCap()
{
	return this->cap;
}

template<class T>
void myArray<T>::print()
{
	if (this->num == 0)
	{
		cout<< "The array is empty!"<<endl;
	}
	else
	{
		cout << "The array is:";
		for (int i = 0; i < this->num; i++)
		{
			cout << this->ptrStart[i] << " ";
		}
		cout << endl;
	}
}
