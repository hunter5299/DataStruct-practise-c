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
void StackInit(Stack* ps){
	assert(ps);
	ps->_a = (STDataType*)malloc(sizeof(STDataType)* 100);
	ps->_top = 0;
	ps->_capacity = 100;
}
//检查容量
void STCapCheck(Stack* ps){
	assert(ps);
	if (ps->_capacity <= ps->_top){
		int newCap = sizeof(STDataType)* (ps->_capacity + 100);
		ps->_a = (STDataType*)realloc(ps->_a,newCap );
		assert(ps->_a);
		ps->_capacity = newCap;
	}
}// 入栈 
void StackPush(Stack* ps, STDataType data){
	assert(ps);
	STCapCheck(ps);
	ps->_a[ps->_top] = data;
	ps->_top++;
}
// 出栈 
void StackPop(Stack* ps){
	assert(ps);
	if (!StackEmpty){
		ps->_top --;
	}
}
// 获取栈顶元素 
STDataType StackTop(Stack* ps){
	assert(ps);
	if (!StackEmpty){
		return ps->_a[ps->_top];
	}
}
// 获取栈中有效元素个数 
int StackSize(Stack* ps){
	assert(ps);
	return ps->_top;
}
// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0 
int StackEmpty(Stack* ps){
	assert(ps);
	return ps->_top == 0 ? 1 : 0;
}
// 销毁栈 
void StackDestroy(Stack* ps){
	assert(ps);
	free(ps->_a);
	ps->_capacity = 0;
	ps->_top = 0;
}