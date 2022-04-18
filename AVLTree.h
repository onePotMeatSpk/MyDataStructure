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
���ܣ������������飬����һ��AVL��
���أ��Ѵ���AVL����ָ��,��arrΪ�������򷵻ؿ�ָ��
arr������
arrLength������ĳ���
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
���ܣ���������ǰ�����
root����ָ��
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
���ܣ����������������
root����ָ��
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
���ܣ�������������ת
root����ָ��
*/
void leftRotate(AVLTree*& root)
{
	AVLTree* R = root->rchild;
	root->rchild = R->lchild;
	R->lchild = root;
	root = R;
}

/*
���ܣ�������������ת
root����ָ��
*/
void rightRotate(AVLTree*& root)
{
	AVLTree* L = root->lchild;
	root->lchild = L->rchild;
	L->rchild = root;
	root = L;
}

/*
���ܣ����������ߵ���������ƽ��
root����ָ��
*/
void leftBalance(AVLTree*& root)
{
	/*�㷨����*/
	/*
	Step1��ȡ��������������
	Step2���ж�������bf�뱾��bf�������Ƿ�һ�£����ж�������ƫ���뱾���Ƿ�һ�£�
		Step2.1��һ�£���ֱ�ӶԱ�����������ת
		Step2.2����һ�£����ȶ���������������ת����֤����bf����һ�º��ٶԱ�����������ת
	*/

	/*Stpe1*/
	AVLTree* L = root->lchild;
	
	/*Stpe2*/
	switch (L->bf)
	{
	/*Stpe2.1*/
	case LH:	
		root->bf = EH;	
		L->bf = EH;		/*�ڴ˴�����root��L�������ȷ���ĸ�ֵ������żȻ�����Ǳ�Ȼ��
						����3��������ܵ���L��rootͬΪLH��������ɻ�ͼ�������*/
		rightRotate(root);
		break;
	/*Stpe2.2*/
	case RH:
		AVLTree* Lr = L->rchild;
		switch (Lr->bf)	/*�ڴ˴�����root��L�������ȷ���ĸ�ֵ������żȻ�����Ǳ�Ȼ��
						����3��������ܵ���L��root����ͬ��������ɻ�ͼ�������*/
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
		root->lchild = L;	/*!!!!!!!!�˴�һ��Ҫ�ǵý�root�����������������ӣ�����
							����ɽڵ㶪ʧ����!!!!!!!!!!*/
		rightRotate(root);
		break;
	}
}

/*
���ܣ����������ߵ���������ƽ�⣨ԭ��ͬ��ƽ���㷨��
root����ָ��
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
���ܣ������ݲ��뵽����
���أ�����ɹ�����SUCCESS�����򷵻�FAILURE
root����ָ��
dataInsert����������
taller�����Ƿ��߱�־λ
*/
bool insertAVL(AVLTree*& root, int dataInsert, bool& taller)
{
	/*�㷨����*/
	/* 
	Step1��ָ�뵽��Ӧ�����λ��
		Step1.1���޸�ֵ��root�ͻ�Ϊ�գ�����в��벢����taller
		Step1.2����ֵ���У��򷵻�FAILURE
	Step2������ֵС������λ�õ�ֵ
		Step2.1���ݹ�������
		Step2.2��taller��������Ƿ�ƽ�⣬��ƽ���������ת
	Step3������ֵ��������λ�õ�ֵ(��Step2ͬ��
		Step3.1���ݹ�������
		Step3.2��taller��������Ƿ�ƽ�⣬��ƽ���������ת
	*/



	/*Step1.1*/
	if (root == NULL)
	{
		AVLTree* nodeNew = new AVLTree(dataInsert);
		root = nodeNew;
		taller = true;	//�ɹ�����Ԫ�ر�Ȼ�����������
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
		/*taller�Ǹ��㷨�ĺ��ģ�ͨ������������taller���ж������߶��Ƿ����ı䣬
		�Ӷ��жϱ����Ƿ���ƽ����������㾭��������taller�п��ܷ����仯���ӱ�����
		�������Ƿ�仯�������������ϴ���taller����ˣ����ݹ飬��ÿһ�㶼ͨ��
		taller�жϱ����Ƿ���Ҫƽ�����*/
		if (taller)		//���������
		{
			switch (root->bf)
			{
			case LH:			//������ߣ��������������룬��Ҫƽ�����
				leftBalance(root);
				taller = false;	//������ƽ������󣬱����߶ȱػع�ԭ���߶ȣ�(��ͼ���)
				break;
			case EH:			//����ƽ�⣬�����������룬�����
				root->bf = LH;
				taller = true;	//��������ߣ���Ȼ���±������
				break;
			case RH:			//������ͣ������������룬��ƽ��
				root->bf = EH;
				taller = false;	//�����������������߶ȣ��������߶����岻��
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

