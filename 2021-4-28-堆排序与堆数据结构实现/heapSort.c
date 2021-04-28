#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
// ��������ж�����

void HeapSort(HPDateType* a, int n){
	//1.����,�����һ����Ҷ�ӽڵ㿪ʼ�����������������µ���
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(a, n, i);
	}
	//2. �����򣬽��������һ��Ҷ�ӽڵ㽻�����˽ڵ㲻�������ĵ������������
	int end = n - 1;
	while (end >= 0){
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}
void Swap(HPDateType* a, HPDateType*b){
	assert(a || b);
	HPDateType t = *a;
	*a = *b;
	*b = t;
}


//���µ�����ɾ���������ǵ���
void AdjustDown(HPDateType* a, int n, int start){
	assert(a || n < 0 || start < 0 || start >= n);
	int parent = start;
	int child = parent * 2 + 1;
	while (child < n ){
		//���Ӵ������ӣ������
		if (child+1 < n && a[child + 1] > a[child]){
			child++;
		}
		//���� С�� �ӣ��򽻻�,�����Ѿ��Ƕѣ�����ѭ��
		if (a[child] > a[parent]){
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else{
			break;
		}
	}
}


//���ϵ���������ʱ����
void AdjustUp(HPDateType* a, int n, int start){
	assert(a || start < 0);
	int parent = (start-1) / 2;
	int child = start;
	while (child >= 0){
		//���ϴ���ѣ����Ӵ��븸���򽻻�
		//С���ѣ�����С�ڸ����򽻻�
		if (a[child] > a[parent]){
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else{
			break;
		}
	}
}
// �ѵĹ���
void HeapCreate(Heap* hp, HPDateType* a, int n){
	assert(hp|| n < 0);
	hp->_a = (HPDateType*)malloc(sizeof(HPDateType)*100);
	if (hp->_a == NULL){
		exit(-1);
	}
	int i = n;
	while (i >= 0){
		hp->_a[i] = a[i];
		i--;
	}
	hp->_capacity = 100;
	hp->_size = n;

	//����,�����һ����Ҷ�ӽ�����µ�������ǰ�������µ���

	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(hp->_a, n, i);
	}
}

// �ѵ�����
void HeapDestory(Heap* hp){
	assert(hp);
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDateType x){
	assert(hp);
//�ȼ��������Ƿ���
	if (hp->_capacity == hp->_size){
		HPDateType* t = (HPDateType*)realloc(hp->_a, hp->_capacity +100);
		if (t == NULL){
			exit(-1);
		}
		hp->_a = t;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ���
	int start = hp->_size - 1;
	AdjustUp(hp->_a,hp->_size, start);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp){
	assert(hp);
	if (hp->_size <= 0){
		exit(-1);
	}
	//�����������һ��Ҷ�ӽ�㣬�ٴӸ����µ���һ��
	Swap(& (hp->_a[0]), & (hp->_a[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDateType HeapTop(Heap* hp){
	assert(hp);
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp){
	assert(hp);
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp){
	assert(hp);
	return hp->_size == 0;
}
void PrintHeap(Heap* hp){
	assert(hp);
	for (int i = 0; i < hp->_size; i++){
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
//1.�Ƚ�ǰk��������С�ģ����ѣ�
//2.�ٽ������n-k��������Ѹ��Աȣ������������������
void PrintTopK(int* a, int n, int k){
	assert(a || k <= 0);
	 
	HPDateType *t = (HPDateType*)malloc(sizeof(HPDateType)*k);
	//ǰk��
	for (int i = 0; i < k; i++){
		t[i] = a[i];
	}
	//����
	for (int i = (k - 2) / 2; i >= 0; i--){
		AdjustDown(t, k, i);
	}
	//�Ա�
	int i = k;
	while (i < n){
		//����ѣ�ѡ��С��k��
		if (t[0] > a[i]){
			t[0] = a[i];
			AdjustDown(t, k, 0);
		}
		i++;
	}
	//��ӡ
	for (int i = 0; i < k; i++){
		printf("%d ", t[i]);
	}
	printf("\n");
}
void TestTopk(){
	int arr[] = { 12, 66, 22, 54, 45, 22, 11, 10, 5, 99 };
	//����ѣ�ѡ��С��3��
	PrintTopK(arr, sizeof(arr) / sizeof(arr[0]), 5);
}
