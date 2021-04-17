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
void StackInit(Stack* ps){
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 100);
	ps->_top = 0;
	ps->_capacity = 100;
}
//�������
void STCapCheck(Stack* ps){
	assert(ps);
	if (ps->_capacity <= ps->_top){
		int newCap = sizeof(STDataType)* (ps->_capacity + 100);
		ps->_a = (STDataType*)realloc(ps->_a,newCap );
		assert(ps->_a);
		ps->_capacity = newCap;
	}
}// ��ջ 
void StackPush(Stack* ps, STDataType data){
	assert(ps);
	STCapCheck(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// ��ջ 
void StackPop(Stack* ps){
	assert(ps);
	if (!StackEmpty){
		ps->_top --;
	}
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps){
	assert(ps);
	if (!StackEmpty){
		return ps->_a[ps->_top];
	}
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps){
	assert(ps);
	return ps->_top;
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps){
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
// ����ջ 
void StackDestroy(Stack* ps){
	assert(ps);
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}