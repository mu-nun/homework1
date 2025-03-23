#include "Queue.h"

//初始化
void InitQueue(Queue* Q)
{
	Q->front = Q->rear = NULL;
}
//判断是否为空
bool IsEmpty(Queue* Q)
{
	return Q->front == NULL;
}
//入队
void EnQueue(Queue* Q, int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	if (IsEmpty(Q)) 
	{
		// 如果队列为空，新节点既是队头也是队尾
		Q->front = Q->rear = new;
	}
	else {
		// 否则，将新节点添加到队尾
		Q->rear->next = new;
		Q->rear = new;  // 更新队尾指针
	}
}
//出队
int DeQueue(Queue* Q)
{
	if (IsEmpty(Q))
	{
		printf("队列为空，无法出队！\n");
		return -1;
	}
	Node* p = Q->front;
	int x = p->data;
	Q->front = Q->front->next;
	if (Q->front == NULL)
		Q->rear = NULL;// 如果队列为空，更新队尾指针
	free(p);
	return x;
}
void menu(void)
{
	printf("队列操作，存储int类型数据\n");
	printf("请选择要进行的操作:\n");
	printf("1.数据入队。\n");
	printf("2.数据出队。\n");
	printf("3.查看数据。\n");
}
// 获取队头元素
int GetFront(Queue* Q) 
{
	if (IsEmpty(Q)) {
		printf("队列为空，无队头元素！\n");
		return -1;  // 返回一个错误值
	}
	return Q->front->data;  // 返回队头元素
}
//用户查看数据
void InspectQueue(Queue* Q)
{
	if (IsEmpty(Q))
	{
		printf("暂时没有数据\n");
		return;
	}
	Node *p = Q->front;
	printf("队列数据：");
	while (p!=NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("\n");
}

