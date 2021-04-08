#define _CRT_SECURE_NO_WARNINGS 1
#include"linkedlist.h"
int test(){
	SListNode* link = NULL;
	printf("尾插\n");
	SListPushBack(&link, 10);
	SListPushBack(&link, 10);
	SListPushFront(&link, 20);
	SListPrint(&link);

	printf("前删\n");
	SListPopFront(&link);
	SListPrint(&link);

	printf("查找10\n");
	SListNode* t = NULL;
	t = SListFind(link, 10);
	SListPrint(&t);

	printf("插入找的结点之后的位置\n");
	SListInsertAfter(t, 40);
	SListPrint(&link);

	printf("删除找的结点之后的位置\n");
	SListEraseAfter(t);
	SListPrint(&link);
	return 0;
}
int main(){
	test();
	system("pause");
	return 0;
}