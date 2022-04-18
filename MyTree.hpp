#pragma once
#include<iostream>
#include<string>
using namespace std;
const auto refValue = '#';


template <class T>
class Node
{


public:
	Node<T>();
	Node<T>(T dataInput);

	T data;
	Node<T>* lchild;
	Node<T>* rchild;
};

template<class T>
inline Node<T>::Node<T>(): data(NULL), lchild(NULL), rchild(NULL)
{
}

template<class T>
inline Node<T>::Node<T>(T dataInput): data(dataInput), lchild(NULL), rchild(NULL)
{
}


//函数：前序构造二叉树
//参数：根节点指针
template<class T>
void createTree(Node<T>*& subtree)
{
	T dataInput;
	cin >> dataInput;
	if (dataInput == refValue)
	{
		return;
	}

	subtree = new Node<T>(dataInput);
	if (subtree == NULL)
	{
		cout<<"内存分配失败！"<<endl;
		exit(1);
	}

	createTree(subtree->lchild);
	createTree(subtree->rchild);
}



//函数：前序遍历二叉树
//根节点指针
template<class T>
void preOrderTraverse(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return;
	}

	cout << subtree->data << " ";

	preOrderTraverse(subtree->lchild);
	preOrderTraverse(subtree->rchild);
}


//函数：中序遍历二叉树
//根节点指针
template<class T>
void inOrderTraverse(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return;
	}

	inOrderTraverse(subtree->lchild);
	cout << subtree->data << " ";
	inOrderTraverse(subtree->rchild);
}



//函数：求树的深度
//参数：根节点指针
//返回值：树的深度
template<class T>
int depth(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}

	int num0 = depth(subtree->lchild);
	int num1 = depth(subtree->rchild);
	int num = num0 > num1 ? num0 : num1;
	num++;
	return num;
}



//函数：叶子数量
//参数：根节点指针
//返回值：叶子数量
template<class T>
int numLeaf(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}

	if (subtree->lchild==NULL&&subtree->rchild==NULL)
	{
		return 1;
	}

	int num = numLeaf(subtree->lchild) + numLeaf(subtree->rchild);

	return num;
}



//函数：节点数量
//参数：根节点指针
//返回值：节点数量
template<class T>
int numNode(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}

	int num = numNode(subtree->lchild) + numNode(subtree->rchild) + 1;
	return num;
}



//函数：树的度
//参数：根节点指针
//返回值：树的度
template<class T>
int degree(Node<T>*& subtree)
{
	if (subtree == NULL)
	{
		return 0;
	}

	if (subtree->lchild == NULL && subtree->rchild == NULL)
	{
		return 0;
	}

	int num0 = degree(subtree->lchild);
	int num1 = degree(subtree->rchild);
	int num;
	if (subtree->lchild != NULL && subtree->rchild != NULL)
	{
		num = 2;
	}
	else
	{
		num = 1;
	}
	num0 = num0 > num1 ? num0 : num1;
	num = num0 > num ? num0 : num;
}

