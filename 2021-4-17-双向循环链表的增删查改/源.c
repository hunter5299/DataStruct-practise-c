#define _CRT_SECURE_NO_WARNINGS 1
#include"dList.h"
/*
*/
int main(){
	DList* head = NULL;
	dListInit(&head);
	dLPushFront(head, 10);
	dLPushFront(head, 9);
	dLPushFront(head, 8);
	dLPushFront(head, 7);
	dLPushFront(head, 6);
	dLPushBack(head, 11);
	/*
	dLPushBack(head, 11);
	dLPushBack(head, 11);
	dLPushBack(head, 11);*/
	DList* pos=dLfindPos(head, 7);
	dLInsert(pos, 13);
	pos = dLfindPos(head, 8);
	dLErase(head, pos);
	printDL(head);
	system("pause");
	return 0;
}