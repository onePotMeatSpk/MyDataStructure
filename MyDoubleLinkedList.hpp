#pragma once
#include<iostream>
#include<string>
using namespace std;

//节点类声明
template <class T> class Node;
//链表类声明
template <class T> class List;


//Node类定义
template <class T>
class Node
{
public:

	friend class List<T>;	//List管理类可以访问Node类的data域

	//构造函数
	Node<T>();

	//构造函数：按data域为elem构造
	Node<T>(T elem);
	
	//前向指针
	Node<T>* previous;

	//后向指针
	Node<T>* next;
private:
	//数据域
	T data;
};


//List类定义
template <class T>
class List
{
public:

	//构造函数
	List();

	//函数：重载[]，返回第index个节点的data域
	T& operator[](int index);

	//函数：判断链表是否为空
	bool isEmpty();

	//函数：在index位置插入data域为elem的新节点
	bool insertNode(int index, T elem);

	//函数：尾插data域为elem的新节点
	bool pushBack(T elem);

	//函数：在index位置删除节点
	bool deleteNode(int index);

	//函数：尾删节点
	bool popBack();


	//函数：将data域为originalElem的节点的data域改为newElem
	bool changeNode(T originalElem, T newElem);

	//函数：返回第index个节点的data域
	T& at(int index);

	//函数：将第index个节点的data域传给elem
	bool getElememt(int index, T& elem);

	//函数：遍历链表
	bool traverse();

	//函数：链表长度
	int length();

	//函数：复制链表
	bool copy(List<T>& list);

	//函数：链表元素翻转
	bool overturn();


	//头结点
	Node<T>* head;

	//链表长度
	int len;
};


//Node类构造函数:构造空节点
template<class T>
inline Node<T>::Node() : data(NULL), previous(NULL), next(NULL)
{
}


//Node类构造函数：构造data域为elem的节点
template<class T>
inline Node<T>::Node(T elem) : data(elem), previous(NULL), next(NULL)
{
}


//List类构造函数：初始化头结点和链表长度
template<class T>
List<T>::List()
{
	this->head = new Node<T>();
	this->head->data = NULL;
	this->head->next = this->head;
	this->head->previous = this->head;

	this->len = 0;	
}


//函数：重载[]，返回第index个节点的data域
template<class T>
T& List<T>::operator[](int index)
{
	Node<T>* p = this->head;
	int i = 0;
	do
	{
		p = p->next;
		i++;
		if (i == index)
		{
			return p->data;
		}
	} while (p->next != this->head);
}


//函数：判断链表是否为空
template<class T>
bool List<T>::isEmpty()
{
	if (this->len == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}


//函数：在index位置插入data域为elem的新节点
template<class T>
bool List<T>::insertNode(int index, T elem)
{
	if (this->len == 0 && index != 1)
	{
		cout << "Please DO NOT input an illegal index!!!" << endl;
		return false;
	}
	if (this->len != 0 && (index <= 0 || index > this->len))
	{
		cout << "Please DO NOT input an illegal index!!!" << endl;
		return false;
	}

	Node<T>* newNode = new Node<T>(elem);
	Node<T>* p = this->head;
	int i = 0;

	do
	{
		p = p->next;
		i++;
	} while (i != index);

	newNode->next = p;
	newNode->previous = p->previous;
	p->previous->next = newNode;
	p->previous = newNode;
	this->len++;
	return true;
}


//函数：尾插data域为elem的新节点
template<class T>
bool List<T>::pushBack(T elem)
{
	/*新建新节点
	* 新建游标节点p
	* 利用p遍历链表内节点，直到p为尾节点
	* 将尾结点next指向新节点
	* 将新节点previous指向尾结点
	* 将新节点next指向头结点
	* 释放p内存
	*/

	Node<T>* newNode = new Node<T>(elem);
	Node<T>* p = this->head;
	do
	{
		p = p->next;
	} while (p->next != this->head);
	p->next = newNode;
	newNode->previous = p;
	newNode->next = this->head;
	this->len++;
	return true;
}


//函数：在index位置删除节点
template<class T>
bool List<T>::deleteNode(int index)
{
	if (index <= 0 || index > this->len)
	{
		cout << "Please DO NOT input an illegal index!!!" << endl;
		return false;
	}

	Node<T>* p = this->head;
	int i = 0;

	do
	{
		p = p->next;
		i++;
	} while (i != index);

	p->previous->next = p->next;
	p->next->previous = p->previous;
	delete p;

	this->len--;
	return true;
}


//函数：尾删节点
template<class T>
bool List<T>::popBack()
{
	if (this->len == 0)
	{
		cout << "This list has been empty!!!" << endl;
		return false;
	}
	Node<T>* p = this->head;
	int i = 0;
	do
	{
		p = p->next;
		i++;
	} while (i!=this->len);
	p->previous->next = this->head;
	this->head->previous = p->previous;
	delete p;
	this->len--;
	return true;
}



//函数：将data域为originalElem的节点的data域改为newElem
template<class T>
bool List<T>::changeNode(T originalElem, T newElem)
{
	Node<T>* p = this->head;
	int i = 0;
	do
	{
		p = p->next;
		i++;
		if (p->data == originalElem)
		{
			p->data = newElem;
		}
	} while (i != this->len);
	return true;
}


//函数：返回第index个节点的data域
template<class T>
T& List<T>::at(int index)
{
	Node<T>* p = this->head;
	int i = 0;
	do
	{
		p = p->next;
		i++;
		if (i == index)
		{
			return p->data;
		}
	} while (p->next != this->head);
}


//函数：将第index个节点的data域传给elem
template<class T>
bool List<T>::getElememt(int index, T& elem)
{
	if (index <= 0 || index > this->len)
	{
		cout << "Please DO NOT input an illegal index!!!" << endl;
		return false;
	}
	if (this->len == 0)
	{
		cout << "This list is EMPTY!!!" << endl;
		return false;
	}
	Node<T>* p = this->head;
	int i = 0;
	do
	{
		p = p->next;
		i++;
		if (i == index)
		{
			elem = p->data;
			return true;
		}
	} while (p->next != this->head);
}


//函数：遍历链表
template<class T>
bool List<T>::traverse()
{
	if (this->len == 0)
	{
		cout << "This list is EMPTY!!!" << endl;
		return false;
	}
	Node<T>* p = this->head;
	do
	{
		p = p->next;
		cout << p->data << " ";
	} while (p->next != this->head);
	cout << endl;
	return true;
}


//函数：链表长
template<class T>
inline int List<T>::length()
{
	return this->len;
}

template<class T>
bool List<T>::copy(List<T>& list)
{
	return false;
}
