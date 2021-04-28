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
// �ѵĹ���
void HeapCreate(Heap* hp, HPDateType* a, int n);
// �ѵ�����
void HeapDestory(Heap* hp);
// �ѵĲ���
void HeapPush(Heap* hp, HPDateType x);
// �ѵ�ɾ��
void HeapPop(Heap* hp);
// ȡ�Ѷ�������
HPDateType HeapTop(Heap* hp);
// �ѵ����ݸ���
int HeapSize(Heap* hp);
// �ѵ��п�
int HeapEmpty(Heap* hp);

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k);
void TestTopk();