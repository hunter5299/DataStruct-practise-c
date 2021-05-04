#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
//typedef int QDataType;
//// 链式结构：表示队列 
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// 队列的结构 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;

// 初始化队列 
void QueueInit(Queue* q){
	assert(q);
	q->_front = NULL;
	q->_rear = q->_front;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data){
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->_data = data;
	newnode->_next = NULL;

	//若队中对元素，则队头队尾指向第一个元素
	if (q->_front = NULL){
		q->_front = q->_rear = newnode;
	}
	else{
		//队尾迭代
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
	
}
// 队头出队列 
void QueuePop(Queue* q){
	assert(q);
	//若头部为NULL，则无元素
	assert(q->_front);
	//若队头队尾相等，则出队后置空
	if (q->_front = q->_rear){
		free(q->_front);
		q->_front = q->_rear = NULL;
	}
	else{
		QNode* next = q->_front->_next;

		free(q->_front);
		q->_front = next;

	}
}
// 获取队列头部元素 
QDataType QueueTop(Queue* q){
	assert(q);
	assert(q->_front);
	if (q->_front != NULL){
		return q->_front->_data;
	}
	else{
		exit(-1);
	}
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q){
	assert(q);
	if (q->_rear != NULL){
		return q->_rear->_data;
	}
	else{
		exit(-1);
	}
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q){
	assert(q);
	int count = 0;
	QNode* cur = q->_front;
	while (cur != q->_rear){
		count++;
		cur = cur->_next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q){
	assert(q);
	return q->_front == NULL ? 1 : 0;
}
// 销毁队列 
void QueueDestroy(Queue* q){
	assert(q);
	while (q->_front != q->_rear){
		QNode* del = q->_front;
		q->_front = q->_front->_next;
		free(del);
	}
	free(q->_front);
	q->_front = q->_rear = NULL;
}