#pragma once
#include<iostream>
#include<string>
using namespace std;

class Tree
{
public:
	Tree();
	Tree(int dataInput);

	int data;
	Tree* lchild;
	Tree* rchild;
};

Tree::Tree(): data(NULL),lchild(NULL),rchild(NULL)
{
}

Tree::Tree(int dataInput): data(dataInput), lchild(NULL), rchild(NULL)
{
}

/*创建二叉排序树
* RETURN:创建的树的根节点指针
* arr[]:用来创建树的数组
* length:数组的长度
*/
Tree* createBST(int arr[], int length)
{
	Tree* tree = NULL;
	int i = 0;
	while (i < length)
	{
		insertBST(tree, arr[i]);
		i++;
	}
	return tree;
}

/*前序遍历
* root:被遍历树的根节点
*/
void preOrderTraverse(Tree* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrderTraverse(root->lchild);
	preOrderTraverse(root->rchild);
}

/*中序遍历
* root:被遍历树的根节点
*/
void inOrderTraverse(Tree* root)
{
	if (root == NULL)
	{
		return;
	}

	inOrderTraverse(root->lchild);
	cout << root->data << " ";
	inOrderTraverse(root->rchild);
}

/*查找最小值
* RETURN:最小值
* root:被遍历树的根节点
*/
int findMin(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}

	while(root->lchild)
	{
		root = root->lchild;
	}
	return root->data;
}

/*查找最大值
* RETURN:最大值
* root:被遍历树的根节点
*/
int findMax(Tree* root)
{
	if (root == NULL)
	{
		return 0;
	}

	while (root->rchild)
	{
		root = root->rchild;
	}
	return root->data;
}

/*查找树中是否有某值并将查到节点的指针用node传出
* RETURN:查到值则返回true,否则为false
* root:被查找树的根节点
* dataSearch:被查找的值
* node:查找到值,则node为该值的指针;否则为该值的父母节点的指针
* parent:父母节点的指针
*/
bool searchBST(Tree* root, int dataSearch, Tree*& node, Tree* parent)
{
	if (root == NULL)
	{
		node = parent;
		return false;
	}

	if (dataSearch == root->data)
	{
		node = root;
		return true;
	}
	else if (dataSearch < root->data)
	{
		return searchBST(root->lchild, dataSearch, node, root);
	}
	else
	{
		return searchBST(root->rchild, dataSearch, node, root);
	}
}

/*查找树中是否有某值
* RETURN:查到值则返回true,否则为false
* root:被查找树的根节点
* dataSearch:被查找的值
*/
bool isContain(Tree* root, int dataSearch)
{
	if (root == NULL)
	{
		return false;
	}

	if (dataSearch == root->data)
	{
		return true;
	}
	else if (dataSearch < root->data)
	{
		return isContain(root->lchild, dataSearch);
	}
	else
	{
		return isContain(root->rchild, dataSearch);
	}
}

/*插入某值到树中
* RETURN:插值成功则返回true,否则为false
* root:被插入的树的根节点
* dataSearch:被插入的值
*/
bool insertBST(Tree*& root, int dataInsert)
{
	Tree* node;
	if (searchBST(root, dataInsert, node))
	{
		return false;
	}
	else if(node == NULL)
	{
		Tree* nodeNew = new Tree(dataInsert);
		root = nodeNew;
		return true;
	}
	else
	{
		Tree* nodeNew = new Tree(dataInsert);
		if (dataInsert < node->data)
		{
			node->lchild = nodeNew;
		}
		else
		{
			node->rchild = nodeNew;
		}
		return true;
	}
}

/*删除某值
* RETURN:删除成功则返回true,否则为false
* root:树的根节点
* dataSearch:被删除的值
*/
bool deleteBST(Tree*& root, int dataDelete)
{
	if (root == NULL)
	{
		return false;
	}

	if (dataDelete < root->data)
	{
		return deleteBST(root->lchild, dataDelete);
	}
	if (dataDelete > root->data)
	{
		return deleteBST(root->rchild, dataDelete);
	}


	if (dataDelete == root->data)
	{
		Tree* temp = root;

		if (root->lchild == NULL)
		{
			root = root->rchild;
			delete temp;
		}
		else if (root->rchild == NULL)
		{
			root = root->lchild;
			delete temp;
		}
		else if (root->lchild != NULL && root->rchild != NULL)
		{
			Tree* pre = root;
			temp = temp->lchild;

			if (temp->rchild)
			{
				pre = temp;
				while (temp->rchild)
				{
					pre = temp;
					temp = temp->rchild;
				}
				root->data = temp->data;
				pre->rchild = temp->lchild;
				delete temp;
			}
			else
			{
				root->data = temp->data;
				pre->lchild = temp->lchild;
				delete temp;
			}
		}
		return true;
	}
}
