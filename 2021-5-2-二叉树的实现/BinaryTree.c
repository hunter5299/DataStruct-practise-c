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
	if (t == NULL){
		return;
	}
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
	if (k - 1 == 0){//�����k��
		return 1;
	}
	int rc = BinaryTreeLevelKSize(root->_left, k - 1);//�������ĵ�k��
	int lc = BinaryTreeLevelKSize(root->_right, k - 1);//�������ĵ�k��ڵ���
	return lc + rc;
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x){
	if (root == NULL){
		return NULL;
	}
	if (root->_data == x){
		return root;
	}
	BTNode* retr = BinaryTreeFind(root->_left, x);	
	//������������x����ֱ�ӷ���
	if (retr != NULL){
		return retr;
	}
	//�����ٴ��������б���Ѱ��
	BTNode* retl=BinaryTreeFind(root->_right, x);
	return retl;
	
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
	if (root != NULL){
		QueuePush(&qu, root);
	}
	else{
		return;
	}
	//���Ӳ�Ϊ��
	while (!QueueEmpty(&qu))
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

	QueueDestroy(&qu);
}
//�ж��Ƿ�Ϊ��ȫ������1 �жϸ��ڵ��������ӣ��ж��ӽڵ��Ƿ����
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

	QueueDestroy(&qu);
	return 1;
}
//�ж��Ƿ�Ϊ��ȫ������2 �������ȫ����ӣ�����null�����������ж϶���ʣ�µ�Ԫ���Ƿ�ȫ��NULL�����ǣ�������ȫ������
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
	//������������ͬʱ���ӣ�������һ���գ�������ѭ��
	while (!QueueEmpty(&qu)){
		cur = QueueTop(&qu);
		QueuePop(&qu);
		if (cur == NULL){
			break;
		}
		QueuePush(&qu, root->_left);
		QueuePush(&qu, root->_right);
	}
	//��������ʣ�µ�Ԫ�أ������ǿգ�������ȫ������������һ���ǿգ����ǣ�����false
	while (!QueueEmpty(&qu)){
		cur = QueueTop(&qu);
		QueuePop(&qu);
		if (cur != NULL){
			return 0;
		}
	}
	QueueDestroy(&qu);
	//������ɣ�����true
	return 1;
}
int main(){
	return 0;
}