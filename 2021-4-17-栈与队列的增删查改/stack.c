#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
// ֧�ֶ�̬������ջ
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// ջ��
//	int _capacity;  // ���� 
//}Stack;
// ��ʼ��ջ 
//��ʵ��ջ�����ݽṹ
void StackInit(Stack* ps){
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 100);
	ps->_top = 0;
	ps->_capacity = 100;
}
//�������
void STCapCheck(Stack* ps){
	if (ps->_capacity <= ps->_top){
		int newCap = sizeof(STDataType)* (ps->_capacity + 10);
		ps->_a = (STDataType*)realloc(ps->_a, newCap);
		ps->_capacity = newCap;
	}
}// ��ջ 
int StackPush(Stack* ps, STDataType data){
	STCapCheck(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
	return data;
}
// ��ջ 
int StackPop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	int ret = ps->_a[ps->_top - 1];
	ps->_top--;
	return ret;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	return ps->_a[ps->_top - 1];
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps){
	return ps->_top == 0 ? 1 : 0;
}
// ����ջ 
void StackDestroy(Stack* ps){
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}