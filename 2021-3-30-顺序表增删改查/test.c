#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

int test(){
	SeqList seq;
	SeqListInit(&seq);
	printf("插入元素---------\n");
	SeqListPushBack(&seq, 10);
	SeqListPushBack(&seq, 20); 
	SeqListPushBack(&seq, 30);
	SeqListPushBack(&seq, 40);
	SeqListPushFront(&seq, 70);
	SeqListPrint(&seq);
	printf("intsert插入元素-下标2 值40--------\n");
	SeqListInsert(&seq, 2, 100);
	SeqListPrint(&seq);
	printf("popfront删除元素----------\n");
	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("popback删除元素----------\n");
	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	printf("erase删除元素-下标1的元素-------\n");
	SeqListErase(&seq, 1);
	SeqListPrint(&seq);

	SeqListDestory(&seq);
	system("pause");
	return 0;
}
int main(){
	test();
	return 0;
}