#define _CRT_SECURE_NO_WARNINGS 1
#include"dList.h"
//typedef int DLdataType;
//typedef struct dListNode{
//	DLdataType val;
//	struct dListNode* next;
//	struct dListNode* prev;
//}DLNode;
//

//��ʼ�������һ���ڱ�λͷ�ڵ�
void dListInit(DList** head){
	assert(head);
	DList* t = (DList*)malloc(sizeof(DList));
	assert(t);
	t->next = t;
	t->prev = t;
	*head = t;
}
void dLDestroy(DList** head){
	assert(head);
	DList *next=(*head)->next;
	while (next != *head){
		DList* del = next;
		next = del->next;
		free(del);
	}
	free(head);
	*head = NULL;
}
void dLPopFront(DList* head){
	assert(head);
	DList* next = head->next;
	if (head != next){
		DList* del = next;
		head->next = next->next;
		head->next->prev = head;

		free(del);
	}
	else{
		printf("����һ��ͷ�ڵ㣬ͷɾʧ�ܣ�\n");
	}
	
}
void dLPopBack(DList* head){
	assert(head);
	DList *tail = head->prev;
	if (tail != head){
		DList* tailPrev = tail->prev;
		tailPrev->next = tail->next;
		head->prev = tailPrev;

		free(tail);
	}
	else{
		printf("����һ��ͷ�ڵ㣬βɾʧ�ܣ�\n");
	}

}
void dLPushFront(DList* head, DLdataType x){
	assert(head);
	DList *newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->val = x;

	DList* next = head->next;
	head->next = newnode;
	newnode->next = next;
	newnode->prev = head;
	next->prev = newnode;

}
void dLPushBack(DList* head, DLdataType x){
	assert(head);
	DList* newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->val = x;

	DList* tail = head->prev;
	newnode->prev = tail;
	newnode->next = head;
	tail->next = newnode;
}
DList* dLfindPos(DList* head, DLdataType x){
	assert(head);
	DList* cur = head->next;
	while (cur != head){
		if (cur->val == x){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void dLErase(DList* head, DList* pos){
	assert(head || pos);
	DList* prev = pos->prev;

	pos->next->prev = prev;
	prev->next = pos->next;
	free(pos);
}
void dLInsert(DList* pos, int x){
	assert(pos);
	DList* newnode = (DList*)malloc(sizeof(DList));
	assert(newnode);
	newnode->val = x;

	DList* prev = pos->prev;
	
	prev->next = newnode;
	newnode->prev = prev;
	pos->prev = newnode;
	newnode->next = pos;
	
}
void printDL(DList* head){
	assert(head);
	DList* cur = head->next;
	while (cur != head){
		printf("%d  ",cur->val);
		cur = cur->next;
	}
	printf("\n");
}