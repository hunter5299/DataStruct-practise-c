#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
typedef int HPDateType;
typedef struct Heap
{
	HPDateType* _a;
	int _size;
	int _capacity;
}Heap;
void Swap(HPDateType* a, HPDateType*b);
void HeapSort(HPDateType* a, int n);
void AdjustDown(HPDateType* a,int n,int start);

void PrintHeap(Heap* hp);
// 堆的构建
void HeapCreate(Heap* hp, HPDateType* a, int n);
// 堆的销毁
void HeapDestory(Heap* hp);
// 堆的插入
void HeapPush(Heap* hp, HPDateType x);
// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDateType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();