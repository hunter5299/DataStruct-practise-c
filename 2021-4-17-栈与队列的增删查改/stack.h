#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
#include<assert.h>
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��,ָ�������ջ������һ��λ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps);
// ��ջ 
int StackPush(Stack* ps, STDataType data);
// ��ջ 
int StackPop(Stack* ps);
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);
// ����ջ 
void StackDestroy(Stack* ps);