#define _CRT_SECURE_NO_WARNINGS 1
#include"queue.h"
//typedef int QDataType;
//// ��ʽ�ṹ����ʾ���� 
//typedef struct QListNode
//{
//	struct QListNode* _next;
//	QDataType _data;
//}QNode;
//
//// ���еĽṹ 
//typedef struct Queue
//{
//	QNode* _front;
//	QNode* _rear;
//}Queue;

// ��ʼ������ 
void QueueInit(Queue* q){
	assert(q);
	q->_front = NULL;
	q->_rear = q->_front;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data){
	assert(q);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);
	newnode->_data = data;
	newnode->_next = NULL;

	//�����ж�Ԫ�أ����ͷ��βָ���һ��Ԫ��
	if (q->_front = NULL){
		q->_front = q->_rear = newnode;
	}
	else{
		//��β����
		q->_rear->_next = newnode;
		q->_rear = newnode;
	}
	
}
// ��ͷ������ 
void QueuePop(Queue* q){
	assert(q);
	//��ͷ��ΪNULL������Ԫ��
	assert(q->_front);
	//����ͷ��β��ȣ�����Ӻ��ÿ�
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
// ��ȡ����ͷ��Ԫ�� 
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
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q){
	assert(q);
	if (q->_rear != NULL){
		return q->_rear->_data;
	}
	else{
		exit(-1);
	}
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q){
	assert(q);
	return q->_front == NULL ? 1 : 0;
}
// ���ٶ��� 
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