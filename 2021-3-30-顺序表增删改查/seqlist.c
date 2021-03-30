#define _CRT_SECURE_NO_WARNINGS 1
#include"seqlist.h"
//
//typedef struct SeqList
//{
//	SLDateType* a;
//	size_t size;
//	size_t capacity; // unsigned int
//}SeqList;

// 对数据的管理:增删查改 
void SeqListInit(SeqList* ps){
	assert(ps);
	ps->capacity = 100;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)* (ps->capacity));
	assert(ps->a);
	ps->size = 0;
}
void SeqListDestory(SeqList* ps){
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

void SeqListPrint(SeqList* ps){
	assert(ps);
	for (int i = 0; i < ps->size; i++){
		printf("%d\n",ps->a[i]);
	}
}
void SeqListPushBack(SeqList* ps, SLDateType x){
	assert(ps);
	SeqLisetCheckCap(ps);
	ps->a[ps->size] = x;
	ps->size++;
}
void SeqLisetCheckCap(SeqList* ps){
	assert(ps);
	if (ps->capacity == ps->size+1){
		SLDateType* temp = NULL;
		temp = (SLDateType*)realloc(ps->a, ps->capacity + 100);
		ps->a = temp;
		ps->capacity += 100;
	}
}
void SeqListPushFront(SeqList* ps, SLDateType x){
	assert(ps);
	SeqLisetCheckCap(ps);
	for (int i = ps->size; i > 0 ;i--){
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[0] = x;
	ps->size++;
}
void SeqListPopFront(SeqList* ps){
	assert(ps);
	if (ps->size > 0){
		for (int i = 0; i < ps -> size -1 ; i ++){
			ps->a[i] = ps->a[i + 1];
		}
		ps->size--;
	}
	else{
		printf("数组内无元素，popfront failed\n");
	}
}
void SeqListPopBack(SeqList* ps){
	assert(ps);
	if (ps->size > 0){
		ps->a[ps->size] = 0;
		ps->size--;
	}
	else{
		printf("数组内无元素，popback failed\n");
	}
}

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x){
	assert(ps);
	for (int i = 0; i < ps->size; i++){
		if (ps->a[i] == x){
			return x;
		}
	}
	return 0;
}
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x){
	assert(ps);
	if (ps->size <= pos||pos < 0){
		printf("插入位置不合法\n");
		return;
	}
	SeqLisetCheckCap(ps);
	for (int i = ps->size; i > pos; i--){
		ps->a[i] = ps->a[i - 1];
	}
	ps->a[pos] = x;
	ps->size++;
}
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos){
	assert(ps);
	if (ps->capacity <= pos || pos < 0){
		printf("删除位置不合法\n");
		return;
	}
	for (int i = pos; i < ps->size; i++){
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}