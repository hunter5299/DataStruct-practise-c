#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"
// 对数组进行堆排序

void HeapSort(HPDateType* a, int n){
	//1.建堆,从最后一个非叶子节点开始调整，往上依次向下调整
	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(a, n, i);
	}
	//2. 堆排序，将根与最后一个叶子节点交换，此节点不参与后面的调整，排序完成
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


//向下调整，删除与排序是调用
void AdjustDown(HPDateType* a, int n, int start){
	assert(a || n < 0 || start < 0 || start >= n);
	int parent = start;
	int child = parent * 2 + 1;
	while (child < n ){
		//右子大于左子，大根堆
		if (child+1 < n && a[child + 1] > a[child]){
			child++;
		}
		//若根 小于 子，则交换,否则已经是堆，跳出循环
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


//向上调整，插入时调用
void AdjustUp(HPDateType* a, int n, int start){
	assert(a || start < 0);
	int parent = (start-1) / 2;
	int child = start;
	while (child >= 0){
		//向上大根堆，若子大与父，则交换
		//小根堆，若子小于父，则交换
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
// 堆的构建
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

	//建堆,从最后一个非叶子结点向下调整，往前依次向下调整

	for (int i = (n - 2) / 2; i >= 0; i--){
		AdjustDown(hp->_a, n, i);
	}
}

// 堆的销毁
void HeapDestory(Heap* hp){
	assert(hp);
	free(hp->_a);
	hp->_capacity = 0;
	hp->_size = 0;
}
// 堆的插入
void HeapPush(Heap* hp, HPDateType x){
	assert(hp);
//先检查堆容量是否够用
	if (hp->_capacity == hp->_size){
		HPDateType* t = (HPDateType*)realloc(hp->_a, hp->_capacity +100);
		if (t == NULL){
			exit(-1);
		}
		hp->_a = t;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整
	int start = hp->_size - 1;
	AdjustUp(hp->_a,hp->_size, start);
}
// 堆的删除
void HeapPop(Heap* hp){
	assert(hp);
	if (hp->_size <= 0){
		exit(-1);
	}
	//交换根到最后一个叶子结点，再从根向下调整一次
	Swap(& (hp->_a[0]), & (hp->_a[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDateType HeapTop(Heap* hp){
	assert(hp);
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp){
	assert(hp);
	return hp->_size;
}
// 堆的判空
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

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
//1.先将前k个当成最小的，建堆，
//2.再将后面的n-k个依次与堆根对比，若满足条件，则进堆
void PrintTopK(int* a, int n, int k){
	assert(a || k <= 0);
	 
	HPDateType *t = (HPDateType*)malloc(sizeof(HPDateType)*k);
	//前k个
	for (int i = 0; i < k; i++){
		t[i] = a[i];
	}
	//建堆
	for (int i = (k - 2) / 2; i >= 0; i--){
		AdjustDown(t, k, i);
	}
	//对比
	int i = k;
	while (i < n){
		//大根堆，选最小的k个
		if (t[0] > a[i]){
			t[0] = a[i];
			AdjustDown(t, k, 0);
		}
		i++;
	}
	//打印
	for (int i = 0; i < k; i++){
		printf("%d ", t[i]);
	}
	printf("\n");
}
void TestTopk(){
	int arr[] = { 12, 66, 22, 54, 45, 22, 11, 10, 5, 99 };
	//大根堆，选最小的3个
	PrintTopK(arr, sizeof(arr) / sizeof(arr[0]), 5);
}
