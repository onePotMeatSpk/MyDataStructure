#pragma once
#include<iostream>
#include<string>
using namespace std;
const auto LH = 1;
const auto EH = 0;
const auto RH = -1;
const auto SUCCESS = true;
const auto FAILURE = false;

class AVLTree
{
public:
	AVLTree();
	AVLTree(int dataInput);

	int data;
	int bf;
	AVLTree* lchild;
	AVLTree* rchild;
};


AVLTree::AVLTree() : data(NULL), bf(EH), lchild(NULL), rchild(NULL) {}

AVLTree::AVLTree(int dataInput) : data(dataInput), bf(EH), lchild(NULL), rchild(NULL) {}

/*
功能：利用已有数组，创建一个AVL树
返回：已创建AVL树的指针,若arr为空数组则返回空指针
arr：数组
arrLength：数组的长度
*/
AVLTree* createAVL(int arr[], int arrLength)
{
	
	if (arrLength == 0)
	{
		return NULL;
	}
	else if (arrLength == 1)
	{
		AVLTree* tree = new AVLTree(arr[0]);
		return tree;
	}
	else
	{
		AVLTree* tree = new AVLTree(arr[0]);
		AVLTree* newNode = NULL;
		for (int i = 1; i < arrLength; i++)
		{
			bool taller = false;
			insertAVL(tree, arr[i],taller);
		}
		return tree;
	}
}

/*
功能：对树进行前序遍历
root：树指针
*/
void preOrederTraverse(AVLTree* root)
{
	if (root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrederTraverse(root->lchild);
	preOrederTraverse(root->rchild);
}

/*
功能：对树进行中序遍历
root：树指针
*/
void inOrederTraverse(AVLTree* root)
{
	if (root == NULL)
	{
		return;
	}

	inOrederTraverse(root->lchild);
	cout << root->data << " ";
	inOrederTraverse(root->rchild);
}

/*
功能：对树进行左旋转
root：树指针
*/
void leftRotate(AVLTree*& root)
{
	AVLTree* R = root->rchild;
	root->rchild = R->lchild;
	R->lchild = root;
	root = R;
}

/*
功能：对树进行右旋转
root：树指针
*/
void rightRotate(AVLTree*& root)
{
	AVLTree* L = root->lchild;
	root->lchild = L->rchild;
	L->rchild = root;
	root = L;
}

/*
功能：对左子树高的树进行左平衡
root：树指针
*/
void leftBalance(AVLTree*& root)
{
	/*算法步骤*/
	/*
	Step1：取出本树的左子树
	Step2：判断左子树bf与本树bf的正负是否一致（即判断左子树偏向与本树是否一致）
		Step2.1：一致，则直接对本树进行右旋转
		Step2.2：不一致，则先对左子树进行左旋转，保证两者bf正负一致后，再对本树进行右旋转
	*/

	/*Stpe1*/
	AVLTree* L = root->lchild;
	
	/*Stpe2*/
	switch (L->bf)
	{
	/*Stpe2.1*/
	case LH:	
		root->bf = EH;	
		L->bf = EH;		/*在此处对于root和L进行如此确定的赋值并不是偶然，而是必然，
						共有3种情况可能导致L与root同为LH的情况，可画图进行理解*/
		rightRotate(root);
		break;
	/*Stpe2.2*/
	case RH:
		AVLTree* Lr = L->rchild;
		switch (Lr->bf)	/*在此处对于root和L进行如此确定的赋值并不是偶然，而是必然，
						共有3种情况可能导致L与root方向不同的情况，可画图进行理解*/
		{
		case LH:
			root->bf = RH;
			L->bf = EH;
			Lr->bf = EH;
			break;
		case EH:
			root->bf = EH;
			L->bf = EH;
			Lr->bf = EH;
			break;
		case RH:
			root->bf = EH;
			L->bf = LH;
			Lr->bf = EH;
			break;
		}
		leftRotate(L);
		root->lchild = L;	/*!!!!!!!!此处一定要记得将root与子树进行重新链接，否则
							会造成节点丢失问题!!!!!!!!!!*/
		rightRotate(root);
		break;
	}
}

/*
功能：对右子树高的树进行右平衡（原理同左平衡算法）
root：树指针
*/
void rightBalance(AVLTree*& root)
{
	/*Stpe1*/
	AVLTree* R = root->rchild;

	/*Stpe2*/
	switch (R->bf)
	{
	case RH:
		root->bf = EH;
		R->bf = EH;
		leftRotate(root);
		break;
	case LH:
		AVLTree* Rl = R->lchild;
		switch (Rl->bf)
		{
		case LH:
			root->bf =LH;
			R->bf = EH;
			Rl->bf = EH;
			break;
		case EH:
			root->bf = EH;
			R->bf = EH;
			Rl->bf = EH;
			break;
		case RH:
			root->bf = EH;
			R->bf = RH;
			Rl->bf = EH;
			break;
		}
		rightRotate(R);
		root->rchild = R;
		leftRotate(root);
		break;
	}
}


/*
功能：将数据插入到树中
返回：插入成功返回SUCCESS，否则返回FAILURE
root：树指针
dataInsert：插入数据
taller：树是否变高标志位
*/
bool insertAVL(AVLTree*& root, int dataInsert, bool& taller)
{
	/*算法步骤*/
	/* 
	Step1：指针到达应插入的位置
		Step1.1：无该值，root就会为空，则进行插入并拉高taller
		Step1.2：该值已有，则返回FAILURE
	Step2：插入值小于现在位置的值
		Step2.1：递归左子树
		Step2.2：taller变高则检查是否不平衡，不平衡则进行旋转
	Step3：插入值大于现在位置的值(与Step2同理）
		Step3.1：递归又子树
		Step3.2：taller变高则检查是否不平衡，不平衡则进行旋转
	*/



	/*Step1.1*/
	if (root == NULL)
	{
		AVLTree* nodeNew = new AVLTree(dataInsert);
		root = nodeNew;
		taller = true;	//成功插入元素必然导致子树变高
		return SUCCESS;
	}

	/*Step1.2*/
	if (dataInsert == root->data)
	{
		return FAILURE;
	}

	/*Step2*/
	if (dataInsert < root->data)
	{
		/*Step2.1*/
		if (!insertAVL(root->lchild, dataInsert, taller))
		{
			return FAILURE;
		}

		/*Step2.2*/
		/*taller是该算法的核心，通过子树传来的taller来判断子树高度是否发生改变，
		从而判断本层是否做平衡操作。本层经过操作后taller有可能发生变化（视本树高
		度最终是否变化而定），再往上传递taller。如此，层层递归，在每一层都通过
		taller判断本层是否需要平衡操作*/
		if (taller)		//若子树变高
		{
			switch (root->bf)
			{
			case LH:			//本身左高，又在左子树插入，需要平衡操作
				leftBalance(root);
				taller = false;	//做完左平衡操作后，本树高度必回归原本高度，(画图理解)
				break;
			case EH:			//本身平衡，在左子树插入，变左高
				root->bf = LH;
				taller = true;	//左子树变高，必然导致本树变高
				break;
			case RH:			//本身左低，在左子树插入，变平衡
				root->bf = EH;
				taller = false;	//左子树赶上右子树高度，但本树高度总体不变
				break;
			}
		}
		return SUCCESS;
	}

	/*Step3*/
	if (dataInsert > root->data)
	{
		/*Step3.1*/
		if (!insertAVL(root->rchild, dataInsert, taller))
		{
			return FAILURE;
		}

		/*Step2.2*/
		if (taller)
		{
			switch (root->bf)
			{
			case RH:
				rightBalance(root);
				taller = false;
				break;
			case EH:
				root->bf = RH;
				taller = true;
				break;
			case LH:
				root->bf = EH;
				taller = false;
				break;
			}
		}
		return SUCCESS;
	}
}

