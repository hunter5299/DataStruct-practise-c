#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"

int test(){
	SeqList seq;
	SeqListInit(&seq);
	printf("����Ԫ��---------\n");
	SeqListPushBack(&seq, 10);
	SeqListPushBack(&seq, 20); 
	SeqListPushBack(&seq, 30);
	SeqListPushBack(&seq, 40);
	SeqListPushFront(&seq, 70);
	SeqListPrint(&seq);
	printf("intsert����Ԫ��-�±�2 ֵ40--------\n");
	SeqListInsert(&seq, 2, 100);
	SeqListPrint(&seq);
	printf("popfrontɾ��Ԫ��----------\n");
	SeqListPopFront(&seq);
	SeqListPrint(&seq);
	printf("popbackɾ��Ԫ��----------\n");
	SeqListPopBack(&seq);
	SeqListPrint(&seq);
	printf("eraseɾ��Ԫ��-�±�1��Ԫ��-------\n");
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