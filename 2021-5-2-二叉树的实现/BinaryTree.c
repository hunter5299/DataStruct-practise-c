#define _CRT_SECURE_NO_WARNINGS 1
#include"BinaryTree.h"
#include"queue.h"
//typedef char BTDataType;
//
//typedef struct BinaryTreeNode
//{
//	BTDataType _data;
//	struct BinaryTreeNode* _left;
//	struct BinaryTreeNode* _right;
//}BTNode;

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi){
	//若a当前指向为# 或已经超过本层可容纳节点数
	if (a[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode * cur = (BTNode *)malloc(sizeof(BTNode));
	cur->_data = a[*pi];
	(*pi)++;

	cur->_left = BinaryTreeCreate(a,n/2,pi);
	cur->_right = BinaryTreeCreate(a,n/2,pi);

	return cur;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode** root){
	BTNode* t = *root;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(t);
	*root = NULL;
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root){
	if (root == NULL){
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root){
	//
	if (root == NULL){
		return 0;
	}
	int flag = 0;
	if (root->_left == NULL && root->_right == NULL){
		flag = 1;
	}
	int lc=BinaryTreeLeafSize(root->_left);
	int rc=BinaryTreeLeafSize(root->_right);
	return flag + lc + rc;
	
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k){
	if (root == NULL){
		return 0;
	}
	if (k - 1 != 0){
		int rc=BinaryTreeLevelKSize(root->_left, k - 1);
		int lc=BinaryTreeLevelKSize(root->_right, k - 1);
		return lc + rc;
	}
	else{
		return 1;
	}
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
	if (root == NULL){
		return NULL;
	}
	if (root->_data == x){
		return root;
	}
	BTNode* retr=BinaryTreeFind(root->_left, x);
	BTNode* retl=BinaryTreeFind(root->_right, x);
	
	if (retr != NULL){
		return retr;
	}
	else{
		return retl;
	}
}
// 二叉树前序遍历 
void BinaryTreePrevOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}
// 层序遍历
//队列实现
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode * cur;

	QueueInit(&qu);
	//根入队
	QueuePush(&qu, root);
	//若队不为空
	while (!QueueIsEmpty(&qu))
	{
		//获取此时的队头元素
		cur = QueueTop(&qu);

		//遍历当前队头元素的值
		putchar(cur->_data);

		//若此元素的左子不为空，则左子入队
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		//若此元素的左子不为空，则左子入队
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		//队头出队
		QueuePop(&qu);
	}

	QueueDestory(&qu);
}
//判断是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->_data);

		//若有右子树单左子树为空，则直接返回false
		if (cur->_right && !cur->_left)
		{
			return 0;
		}
		//若父节点无右子，且当前节点 左子右子 存在，直接返回false
		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}

		//若左子存在，则左子入队
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		//若右子存在，则右子入队
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		//否则试标记为1，表示无右子
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}
