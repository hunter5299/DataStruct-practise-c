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
	if (t == NULL){
		return;
	}
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
	if (k - 1 == 0){//到达第k层
		return 1;
	}
	int rc = BinaryTreeLevelKSize(root->_left, k - 1);//左子树的第k层
	int lc = BinaryTreeLevelKSize(root->_right, k - 1);//右子树的第k层节点数
	return lc + rc;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
	if (root == NULL){
		return NULL;
	}
	if (root->_data == x){
		return root;
	}
	BTNode* retr = BinaryTreeFind(root->_left, x);	
	//若左子树存在x，则直接返回
	if (retr != NULL){
		return retr;
	}
	//否则再从右子树中遍历寻找
	BTNode* retl=BinaryTreeFind(root->_right, x);
	return retl;
	
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
	if (root != NULL){
		QueuePush(&qu, root);
	}
	else{
		return;
	}
	//若队不为空
	while (!QueueEmpty(&qu))
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

	QueueDestroy(&qu);
}
//判断是否为完全二叉树1 判断父节点有无右子，判断子节点是否存在
int BinaryTreeComplete1(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	if (root != NULL){
		QueuePush(&qu, root);
	}
	else{
		return 1;
	}

	while (!QueueEmpty(&qu))
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

	QueueDestroy(&qu);
	return 1;
}
//判断是否为完全二叉树2 层序遍历全部入队，遇到null则跳出，再判断队中剩下的元素是否全是NULL，若是，则是完全二叉树
int BinaryTreeComplete2(BTNode* root)
{
	Queue qu;
	BTNode * cur;
	int tag = 0;

	QueueInit(&qu);

	if (root != NULL){
		QueuePush(&qu, root);
	}
	else{
		return 1;
	}
	//层序遍历，入队同时出队，若遇到一个空，则跳出循环
	while (!QueueEmpty(&qu)){
		cur = QueueTop(&qu);
		QueuePop(&qu);
		if (cur == NULL){
			break;
		}
		QueuePush(&qu, root->_left);
		QueuePush(&qu, root->_right);
	}
	//遍历队中剩下的元素，若都是空，则是完全二叉树，若有一个非空，则不是，返回false
	while (!QueueEmpty(&qu)){
		cur = QueueTop(&qu);
		QueuePop(&qu);
		if (cur != NULL){
			return 0;
		}
	}
	QueueDestroy(&qu);
	//遍历完成，返回true
	return 1;
}
int main(){
	return 0;
}