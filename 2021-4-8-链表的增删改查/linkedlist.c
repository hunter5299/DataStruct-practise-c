#include"linkedlist.h"
//typedef int SLTDateType;
//typedef struct SListNode
//{
//	SLTDateType data;
//	struct SListNode* next;
//}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x);
// 单链表打印
void SListPrint(SListNode** plist){
	assert(plist);
	SListNode* t = *plist;
	while (t != NULL){
		printf("%d ", t->data);
		t = t->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x){
	assert(pplist);
	SListNode* t = *pplist;
	SListNode* newnode = (SListNode*)malloc(sizeof(SListNode));
	newnode->next = NULL;
	if ( NULL == t){	//若传入的是一个空指针
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
// 单链表的头插
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
// 单链表的尾删
void SListPopBack(SListNode** pplist){
	assert(pplist);
	SListNode* t = *pplist;
	if (NULL == t){
		return;
	}
	else{
		SListNode* det = t->next;
		if (NULL == det){	//若删除的是第一个节点
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
// 单链表头删
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
// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x){
	assert(plist);
	int count = 0;
	while (x != plist->data){
		plist = plist->next;
		count++;
	}
	return plist;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？

//答：单向链表找不到前驱结点，除非传入头节点与插入位置
void SListInsertAfter(SListNode* pos, SLTDateType x){
	assert(pos);
	SListNode* t = (SListNode*)malloc(sizeof(SListNode));
	t->data = x;
	t->next = NULL;
	
	t->next = pos->next;
	pos->next = t;
}
// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？

//答：若删除pos位置，因为无法获得前驱结点，会使前驱结点丢失后面的链表
void SListEraseAfter(SListNode* pos){
	assert(pos);
	SListNode* t = pos->next;
	/*若传入的是尾结点*/
	if (NULL == t){
		return;
	}
	pos->next = t->next;;
	
	free(t);
	t = NULL;
}
// 单链表的销毁
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
