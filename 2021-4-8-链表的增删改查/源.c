#define _CRT_SECURE_NO_WARNINGS 1
#include"linkedlist.h"
int test(){
	SListNode* link = NULL;
	printf("β��\n");
	SListPushBack(&link, 10);
	SListPushBack(&link, 10);
	SListPushFront(&link, 20);
	SListPrint(&link);

	printf("ǰɾ\n");
	SListPopFront(&link);
	SListPrint(&link);

	printf("����10\n");
	SListNode* t = NULL;
	t = SListFind(link, 10);
	SListPrint(&t);

	printf("�����ҵĽ��֮���λ��\n");
	SListInsertAfter(t, 40);
	SListPrint(&link);

	printf("ɾ���ҵĽ��֮���λ��\n");
	SListEraseAfter(t);
	SListPrint(&link);
	return 0;
}
int main(){
	test();
	system("pause");
	return 0;
}