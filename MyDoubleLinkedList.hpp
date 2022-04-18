#pragma once
#include<iostream>
#include<string>
using namespace std;

//�ڵ�������
template <class T> class Node;
//����������
template <class T> class List;


//Node�ඨ��
template <class T>
class Node
{
public:

	friend class List<T>;	//List��������Է���Node���data��

	//���캯��
	Node<T>();

	//���캯������data��Ϊelem����
	Node<T>(T elem);
	
	//ǰ��ָ��
	Node<T>* previous;

	//����ָ��
	Node<T>* next;
private:
	//������
	T data;
};


//List�ඨ��
template <class T>
class List
{
public:

	//���캯��
	List();

	//����������[]�����ص�index���ڵ��data��
	T& operator[](int index);

	//�������ж������Ƿ�Ϊ��
	bool isEmpty();

	//��������indexλ�ò���data��Ϊelem���½ڵ�
	bool insertNode(int index, T elem);

	//������β��data��Ϊelem���½ڵ�
	bool pushBack(T elem);

	//��������indexλ��ɾ���ڵ�
	bool deleteNode(int index);

	//������βɾ�ڵ�
	bool popBack();


	//��������data��ΪoriginalElem�Ľڵ��data���ΪnewElem
	bool changeNode(T originalElem, T newElem);

	//���������ص�index���ڵ��data��
	T& at(int index);

	//����������index���ڵ��data�򴫸�elem
	bool getElememt(int index, T& elem);

	//��������������
	bool traverse();

	//������������
	int length();

	//��������������
	bool copy(List<T>& list);

	//����������Ԫ�ط�ת
	bool overturn();


	//ͷ���
	Node<T>* head;

	//������
	int len;
};


//Node�๹�캯��:����սڵ�
template<class T>
inline Node<T>::Node() : data(NULL), previous(NULL), next(NULL)
{
}


//Node�๹�캯��������data��Ϊelem�Ľڵ�
template<class T>
inline Node<T>::Node(T elem) : data(elem), previous(NULL), next(NULL)
{
}


//List�๹�캯������ʼ��ͷ����������
template<class T>
List<T>::List()
{
	this->head = new Node<T>();
	this->head->data = NULL;
	this->head->next = this->head;
	this->head->previous = this->head;

	this->len = 0;	
}


//����������[]�����ص�index���ڵ��data��
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


//�������ж������Ƿ�Ϊ��
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


//��������indexλ�ò���data��Ϊelem���½ڵ�
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


//������β��data��Ϊelem���½ڵ�
template<class T>
bool List<T>::pushBack(T elem)
{
	/*�½��½ڵ�
	* �½��α�ڵ�p
	* ����p���������ڽڵ㣬ֱ��pΪβ�ڵ�
	* ��β���nextָ���½ڵ�
	* ���½ڵ�previousָ��β���
	* ���½ڵ�nextָ��ͷ���
	* �ͷ�p�ڴ�
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


//��������indexλ��ɾ���ڵ�
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


//������βɾ�ڵ�
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



//��������data��ΪoriginalElem�Ľڵ��data���ΪnewElem
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


//���������ص�index���ڵ��data��
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


//����������index���ڵ��data�򴫸�elem
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


//��������������
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


//����������
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
