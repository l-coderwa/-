#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"Queue.h"


BTNode* TreeCreate()
{
	BTNode* n1 = (BTNode*)malloc(sizeof(BTNode));
	assert(n1);
	BTNode* n2 = (BTNode*)malloc(sizeof(BTNode));
	assert(n2);
	BTNode* n3 = (BTNode*)malloc(sizeof(BTNode));
	assert(n3);
	BTNode* n4 = (BTNode*)malloc(sizeof(BTNode));
	assert(n4);
	BTNode* n5 = (BTNode*)malloc(sizeof(BTNode));
	assert(n5);
	BTNode* n6 = (BTNode*)malloc(sizeof(BTNode));
	assert(n6);

	n1->data = 1;
	n2->data = 2;
	n3->data = 3;
	n4->data = 4;
	n5->data = 5;
	n6->data = 6;

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	n2->right = NULL;
	n3->left = NULL;
	n3->right = NULL;
	n4->left = n5;
	n4->right = n6;

	n5->left = NULL;
	n5->right = NULL;
	n6->right = NULL;
	n6->left = NULL;

	return n1;
}


// 二叉树节点的个数  

int  BinaryTreeSize(BTNode* root)
{
	return root == NULL? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}


//二叉树叶子节点的个数

int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;

	return BinaryTreeLeafSize(root->right) + BinaryTreeLeafSize(root->right);

}

//  二叉树的高度
int BinaryTreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int l = BinaryTreeHeight(root->left);
	int r = BinaryTreeHeight(root->right);

	return l > r ? l + 1 : r + 1;
}


// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	assert(k>0);

	if (root==NULL)
		return 0;
	if (k == 1)
		return 1;

	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);

}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return;

	if (root->data == x)
		return root;

	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret)
		return lret;

	BTNode* rret = BinaryTreeFind(root->right, x);
	if (rret)
		return rret;

	return NULL;
}


// 二叉树的前序遍历
void preorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	preorder(root->left);
	preorder(root->right);
}



// 二叉树的中序遍历
void Inorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Inorder(root->left);
	printf("%d ", root->data);
	Inorder(root->right);
}

//二叉树的后序遍历
void Postorder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ", root->data);
}

void BinaryDestroy(BTNode* root)
{
	if (root == NULL)
		return;

	BinaryDestroy(root->left);
	BinaryDestroy(root->right);
	free(root);
}


// 层序遍历

void BinaryLevelOrder(BTNode* root)
{
	QE q;
	QueueInit(&q);
	if (root)
		QueuePush(&q,root);
	
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueTop(&q);
		QueuePop(&q);
		printf("%d ", front->data);

		if (front->left)
			QueuePush(&q, front->left);
		if (front->right)
			QueuePush(&q, front->right);
	}
	printf("\n");
	QueueDestroy(&q);
}

// 判断二叉树是否为完全二叉树

int BinaryTreeComplete(BTNode* root)
{
	QE q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueTop(root);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		QueuePush(&q, front->left);
		QueuePush(&q, front->right);
	}

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueTop(root);
		QueuePop(&q);

		if (front != NULL)
		{
			QueueDestroy(&q);
			return false;
		}
	}
	QueueDestroy(&q);
	return true;
}

int main()
{
	BTNode* root = TreeCreate();



	printf("Tree size:%d\n", BinaryTreeSize(root));
	printf("Tree size:%d\n", BinaryTreeSize(root));
	printf("Tree size:%d\n", BinaryTreeSize(root));

	printf("Tree Leaf size:%d\n", BinaryTreeLeafSize(root));
	printf("Tree Height:%d\n", BinaryTreeHeight(root));
	printf("Tree K Level:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("Tree Find:%p\n", BinaryTreeFind(root, 2));


	BinaryLevelOrder(root);

	preorder(root);
	printf("\n");

	Inorder(root);
	printf("\n");

	Postorder(root);
	printf("\n");



	return 0;
}