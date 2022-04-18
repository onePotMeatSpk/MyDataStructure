#pragma once
#include<string>
#include<iostream>
using namespace std;

template <class T> class Node;//�ڵ���
template <class T> class List;//������

//�ڵ���
template <class T>
class Node
{
public:
	Node(T element);
	friend class List<T>;

private:
	T data;//������
	Node<T>* next;//ָ����
};


//�б���
template <class T>
class List
{
public:
	List();

	//��������ȡ��index���ڵ��������
	bool getElement(int index, T& element);

	//������β���½ڵ�
	bool pushBack(T element);

	
	//�������ڵ�index���ڵ��λ�ò���������Ϊelement���½ڵ�
	bool insertElement(int index, T element);

	//������ɾ����index���ڵ�
	bool deleteNode(int index);

	//���������ĵ�index���ڵ��������
	bool changeElement(int index, T element);
	
	//����������Ƿ�Ϊ��
	bool isEmpty();

	//��������ӡ�����ڵ�������
	void print();

private:
	//ͷ��㲻��Ҫ������
	Node<T>* head;//ͷ�ڵ�ָ����
};

template<class T>
Node<T>::Node(T element):data(element), next(NULL)
{
}

template<class T>
List<T>::List(): head(NULL)
{
}


//��������ȡ��index���ڵ��������
template<class T>
bool List<T>::getElement(int index, T& element)
{
	//��������Ƿ�Ϊ��
	if (this->head == NULL)
	{
		return false;
	}
	//��Ϊ��
	else
	{
		//�����α�ڵ�
		Node<T>* p = this->head;
		//�����α����
		int i = 1;
		//��һ���
		while (p != NULL)
		{
			//����α���������������Ƿ�һ��
			//һ����Ϊelement��ֵ������true
			if (i == index)
			{
				element = p->data;
				return true;
			}
			//��һ�����α�ڵ�����ƽ�
			else
			{
				p = p->next;
				i++;
			}
		}
	}
	//��������β��������false
	return false;
}


//����:β���½ڵ�
template<class T>
bool List<T>::pushBack(T element)
{
	//�����α�ڵ�
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


//�������ڵ�index���ڵ��λ�ò���������Ϊelement���½ڵ�
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


//������ɾ����index���ڵ�
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


//���������ĵ�index���ڵ��������
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


//����������Ƿ�Ϊ��
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


//��������ӡ�����ڵ�������
template<class T>
void List<T>::print()
{
	if (this->head == NULL)
	{
		cout << "This list is empty!" << endl;
	}
	else
	{
		//�����α�ڵ�
		Node<T>* p = this->head;

		//��һ�ж��Ƿ�Ϊ����β��������������ƽ��α�ڵ�
		while (p!= NULL)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}


