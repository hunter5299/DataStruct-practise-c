#define _CRT_SECURE_NO_WARNINGS 1
#include"stack.h"
// 支持动态增长的栈
//typedef int STDataType;
//typedef struct Stack
//{
//	STDataType* _a;
//	int _top;		// 栈顶
//	int _capacity;  // 容量 
//}Stack;
// 初始化栈 
//先实现栈的数据结构
void StackInit(Stack* ps){
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 100);
	ps->_top = 0;
	ps->_capacity = 100;
}
//检查容量
void STCapCheck(Stack* ps){
	if (ps->_capacity <= ps->_top){
		int newCap = sizeof(STDataType)* (ps->_capacity + 10);
		ps->_a = (STDataType*)realloc(ps->_a, newCap);
		ps->_capacity = newCap;
	}
}// 入栈 
int StackPush(Stack* ps, STDataType data){
	STCapCheck(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
	return data;
}
// 出栈 
int StackPop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	int ret = ps->_a[ps->_top - 1];
	ps->_top--;
	return ret;
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps){
	if (StackEmpty(ps)){
		exit(-1);
	}
	return ps->_a[ps->_top - 1];
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps){
	return ps->_top == 0 ? 1 : 0;
}
// 销毁栈 
void StackDestroy(Stack* ps){
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}