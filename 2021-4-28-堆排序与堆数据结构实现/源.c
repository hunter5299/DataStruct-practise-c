#define _CRT_SECURE_NO_WARNINGS 1
#include"heap.h"

void test1(){
	int arr[] = { 12, 66, 22, 54, 45, 22, 11, 10, 5, 99 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
void test(){
	int arr[] = { 12, 66, 22, 54, 45, 22, 11, 10, 5, 99 };
	Heap hp;
	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HPDateType top = HeapTop(&hp); 
	PrintHeap(&hp);

	HeapPush(&hp, 100);
	PrintHeap(&hp);

	HeapPop(&hp);
	PrintHeap(&hp);

	int empty = HeapEmpty(&hp);
	int size = HeapSize(&hp);

	HeapDestory(&hp);
}
void test2(){
	TestTopk();
}
int main(){
	test2();
	system("pause");
	return 0;
}