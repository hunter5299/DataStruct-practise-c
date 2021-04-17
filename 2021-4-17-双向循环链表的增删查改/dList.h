#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int DLdataType;
typedef struct dListNode{
	DLdataType val;
	struct dListNode* next;
	struct dListNode* prev;
}DList;

void dListInit(DList** head);
void dLDestroy(DList** head);
void dLPopFront(DList* head);
void dLPopBack(DList* head);
void dLPushFront(DList* head, DLdataType x);
void dLPushBack(DList* head, DLdataType x);
void dLErase(DList* head, DList* pos);
void dLInsert(DList* pos, int x);
DList* dLfindPos(DList* head, DLdataType x);
void printDL(DList* head);