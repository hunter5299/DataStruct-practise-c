#include"linkedlist.h"
//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x);
// �������ӡ
void SListPrint(SListNode** plist){
	assert(plist);
	SListNode* t = *plist;
	while (t != NULL){
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x){
	assert(pplist);
	SListNode* t = *pplist;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->next = NULL;
	if ( NULL == t){	//���������һ����ָ��
		*pplist = newnode;
	}
	else{
		while (t->next != NULL){
			t = t->next;
		}
		t->next = newnode;
	}
	newnode->data = x;
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x){
	assert(pplist);
	SListNode* t = *pplist;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->next = t;
	newnode->data = x;
	*pplist = newnode;
	t = NULL;
	newnode = NULL;
}
// �������βɾ
void SListPopBack(SListNode** pplist){
	assert(pplist);
	SListNode* t = *pplist;
	if (NULL == t){
		return;
	}
	else{
		SListNode* det = t->next;
		if (NULL == det){	//��ɾ�����ǵ�һ���ڵ�
			det = t;
			*pplist = NULL;
		}
		else{
			while (det->next != NULL){
				det = det->next;
				t = t->next;
			}
		}
		t->next = NULL;
		free(det);
		det = NULL;
	}
	t = NULL;
}
// ������ͷɾ
void SListPopFront(SListNode** pplist){
	assert(pplist);
	SListNode* t = *pplist;
	if (NULL == t){
		return;
	}
	else{
		t = (*pplist)->next;
		free(*pplist);
		*pplist = t;
	}
}
// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x){
	assert(plist);
	int count = 0;
	while (x != plist->data){
		plist = plist->next;
		count++;
	}
	return plist;
}
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿

//�𣺵��������Ҳ���ǰ����㣬���Ǵ���ͷ�ڵ������λ��
void SListInsertAfter(SListNode* pos, SLTDateType x){
	assert(pos);
	SListNode* t = (SListNode*)malloc(sizeof(SListNode));
	t->data = x;
	t->next = NULL;
	
	t->next = pos->next;
	pos->next = t;
}
// ������ɾ��posλ��֮���ֵ
// ����˼��Ϊʲô��ɾ��posλ�ã�

//����ɾ��posλ�ã���Ϊ�޷����ǰ����㣬��ʹǰ����㶪ʧ���������
void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode* t = pos->next;
	/*���������β���*/
	if (NULL == t){
		return;
	}
	pos->next = t->next;;
	
	free(t);
	t = NULL;
}
// �����������
void SListDestory(SListNode* plist){
	assert(plist);
	SListNode* t = plist;
	while (plist != NULL){
		t = plist;
		plist = plist->next;
		free(t);
	}
	t = NULL;
	plist = NULL;
}
