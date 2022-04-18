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

/*��������������
* RETURN:���������ĸ��ڵ�ָ��
* arr[]:����������������
* length:����ĳ���
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

/*ǰ�����
* root:���������ĸ��ڵ�
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

/*�������
* root:���������ĸ��ڵ�
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

/*������Сֵ
* RETURN:��Сֵ
* root:���������ĸ��ڵ�
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

/*�������ֵ
* RETURN:���ֵ
* root:���������ĸ��ڵ�
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

/*���������Ƿ���ĳֵ�����鵽�ڵ��ָ����node����
* RETURN:�鵽ֵ�򷵻�true,����Ϊfalse
* root:���������ĸ��ڵ�
* dataSearch:�����ҵ�ֵ
* node:���ҵ�ֵ,��nodeΪ��ֵ��ָ��;����Ϊ��ֵ�ĸ�ĸ�ڵ��ָ��
* parent:��ĸ�ڵ��ָ��
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

/*���������Ƿ���ĳֵ
* RETURN:�鵽ֵ�򷵻�true,����Ϊfalse
* root:���������ĸ��ڵ�
* dataSearch:�����ҵ�ֵ
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

/*����ĳֵ������
* RETURN:��ֵ�ɹ��򷵻�true,����Ϊfalse
* root:����������ĸ��ڵ�
* dataSearch:�������ֵ
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

/*ɾ��ĳֵ
* RETURN:ɾ���ɹ��򷵻�true,����Ϊfalse
* root:���ĸ��ڵ�
* dataSearch:��ɾ����ֵ
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
