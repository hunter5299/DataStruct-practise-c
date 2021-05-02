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

// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi){
	//��a��ǰָ��Ϊ# ���Ѿ�������������ɽڵ���
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
// ����������
void BinaryTreeDestory(BTNode** root){
	BTNode* t = *root;
	BinaryTreeDestory(&(*root)->_left);
	BinaryTreeDestory(&(*root)->_right);
	free(t);
	*root = NULL;
}
// �������ڵ����
int BinaryTreeSize(BTNode* root){
	if (root == NULL){
		return 0;
	}
	return BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right) + 1;
}
// ������Ҷ�ӽڵ����
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
// ��������k��ڵ����
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
// ����������ֵΪx�Ľڵ�
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
// ������ǰ����� 
void BinaryTreePrevOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	BinaryTreePrevOrder(root->_left);
	printf("%c ", root->_data);
	BinaryTreePrevOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root){
	if (root == NULL){
		return;
	}
	BinaryTreePrevOrder(root->_left);
	BinaryTreePrevOrder(root->_right);
	printf("%c ", root->_data);
}
// �������
//����ʵ��
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode * cur;

	QueueInit(&qu);
	//�����
	QueuePush(&qu, root);
	//���Ӳ�Ϊ��
	while (!QueueIsEmpty(&qu))
	{
		//��ȡ��ʱ�Ķ�ͷԪ��
		cur = QueueTop(&qu);

		//������ǰ��ͷԪ�ص�ֵ
		putchar(cur->_data);

		//����Ԫ�ص����Ӳ�Ϊ�գ����������
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		//����Ԫ�ص����Ӳ�Ϊ�գ����������
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		//��ͷ����
		QueuePop(&qu);
	}

	QueueDestory(&qu);
}
//�ж��Ƿ�Ϊ��ȫ������
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

		//������������������Ϊ�գ���ֱ�ӷ���false
		if (cur->_right && !cur->_left)
		{
			return 0;
		}
		//�����ڵ������ӣ��ҵ�ǰ�ڵ� �������� ���ڣ�ֱ�ӷ���false
		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}

		//�����Ӵ��ڣ����������
		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}
		//�����Ӵ��ڣ����������
		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		//�����Ա��Ϊ1����ʾ������
		else
		{
			tag = 1;
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
	return 1;
}
