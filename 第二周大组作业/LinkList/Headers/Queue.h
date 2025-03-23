#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include < stdbool.h >
//队列结点
typedef struct Node {
	int data;
	struct  Node* next;
}Node;
//链式队列
typedef struct {
	Node* front, * rear;
}Queue;
void InitQueue(Queue* Q);
bool IsEmpty(Queue* Q);
int DeQueue(Queue* Q);
void menu(void);
void EnQueue(Queue* Q, int data);
void InspectQueue(Queue* Q);
int GetFront(Queue* Q);
