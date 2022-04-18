#pragma once
#include<string>
#include<iostream>
using namespace std;

template <class T> class Node;//节点类
template <class T> class List;//链表类

//节点类
template <class T>
class Node
{
public:
	Node(T element);
	friend class List<T>;

private:
	T data;//数据域
	Node<T>* next;//指针域
};


//列表类
template <class T>
class List
{
public:
	List();

	//函数：获取第index个节点的数据域
	bool getElement(int index, T& element);

	//函数：尾插新节点
	bool pushBack(T element);

	
	//函数：在第index个节点的位置插入数据域为element的新节点
	bool insertElement(int index, T element);

	//函数：删除第index个节点
	bool deleteNode(int index);

	//函数：更改第index个节点的数据域
	bool changeElement(int index, T element);
	
	//函数：检查是否为空
	bool isEmpty();

	//函数：打印各个节点数据域
	void print();

private:
	//头结点不需要数据域
	Node<T>* head;//头节点指针域
};

template<class T>
Node<T>::Node(T element):data(element), next(NULL)
{
}

template<class T>
List<T>::List(): head(NULL)
{
}


//函数：获取第index个节点的数据域
template<class T>
bool List<T>::getElement(int index, T& element)
{
	//检查链表是否为空
	if (this->head == NULL)
	{
		return false;
	}
	//不为空
	else
	{
		//创建游标节点
		Node<T>* p = this->head;
		//创建游标计数
		int i = 1;
		//逐一检查
		while (p != NULL)
		{
			//检查游标计数与欲检索数是否一致
			//一致则为element赋值，返回true
			if (i == index)
			{
				element = p->data;
				return true;
			}
			//不一致则将游标节点向后推进
			else
			{
				p = p->next;
				i++;
			}
		}
	}
	//到达链表尾部，返回false
	return false;
}


//函数:尾插新节点
template<class T>
bool List<T>::pushBack(T element)
{
	//创建游标节点
	Node<T>* p = this->head;
	if (this->head == NULL)
	{
		Node<T>* newnode = new Node<T>(element);
		this->head = newnode;
	}
	else
	{
		while (p->next !=NULL)
		{
			p = p->next;
		}
		Node<T>* newnode = new Node<T>(element);
		p->next = newnode;
	}
	return true;
}


//函数：在第index个节点的位置插入数据域为element的新节点
template<class T>
bool List<T>::insertElement(int index, T element)
{
	if (index <= 0 || this->head == NULL)
	{
		return false;
	}
	else
	{
		if (1 == index)
		{
			Node<T>* newnode = new Node<T>(element);
			newnode->next = this->head;
			this->head = newnode;
			return true;
		}

		Node<T>* p = this->head;
		int i = 2;
		do
		{
			if (i == index)
			{
				Node<T>* newnode = new Node<T>(element);
				newnode->next = p->next;
				p->next = newnode;
				return true;
			}
			else
			{
				p = p->next;
				i++;
			}
		} while (p!=NULL);
		return false;
	}
}


//函数：删除第index个节点
template<class T>
bool List<T>::deleteNode(int index)
{
	if (this->isEmpty())
	{
		return false;
	}
	else
	{
		int i = 1;
		Node<T>* p = this->head;
		while (p->next !=NULL)
		{
			p = p->next;
			i++;
			if ((i+1) == index && p->next != NULL)
			{
				Node<T>* q = p->next;
				p->next = q->next;
				delete q;
				return true;
			}
		}
		return false;
	}
}


//函数：更改第index个节点的数据域
template<class T>
bool List<T>::changeElement(int index, T element)
{
	if (this->head == NULL || index <= 0)
	{
		return false;
	}
	else 
	{
		Node<T>* p = this->head;
		int i = 1;
		do
		{
			if (i == index)
			{
				p->data = element;
				return true;
			}
			else
			{
				p = p->next;
				i++;
			}
		} while (p != NULL);
		return false;
	}
}


//函数：检查是否为空
template<class T>
bool List<T>::isEmpty()
{
	if (this->head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//函数：打印各个节点数据域
template<class T>
void List<T>::print()
{
	if (this->head == NULL)
	{
		cout << "This list is empty!" << endl;
	}
	else
	{
		//创建游标节点
		Node<T>* p = this->head;

		//逐一判断是否为链表尾，若不是则向后推进游标节点
		while (p!= NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}


