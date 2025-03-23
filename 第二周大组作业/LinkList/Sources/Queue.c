#include "Queue.h"

//��ʼ��
void InitQueue(Queue* Q)
{
	Q->front = Q->rear = NULL;
}
//�ж��Ƿ�Ϊ��
bool IsEmpty(Queue* Q)
{
	return Q->front == NULL;
}
//���
void EnQueue(Queue* Q, int data)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;
	if (IsEmpty(Q)) 
	{
		// �������Ϊ�գ��½ڵ���Ƕ�ͷҲ�Ƕ�β
		Q->front = Q->rear = new;
	}
	else {
		// ���򣬽��½ڵ���ӵ���β
		Q->rear->next = new;
		Q->rear = new;  // ���¶�βָ��
	}
}
//����
int DeQueue(Queue* Q)
{
	if (IsEmpty(Q))
	{
		printf("����Ϊ�գ��޷����ӣ�\n");
		return -1;
	}
	Node* p = Q->front;
	int x = p->data;
	Q->front = Q->front->next;
	if (Q->front == NULL)
		Q->rear = NULL;// �������Ϊ�գ����¶�βָ��
	free(p);
	return x;
}
void menu(void)
{
	printf("���в������洢int��������\n");
	printf("��ѡ��Ҫ���еĲ���:\n");
	printf("1.������ӡ�\n");
	printf("2.���ݳ��ӡ�\n");
	printf("3.�鿴���ݡ�\n");
}
// ��ȡ��ͷԪ��
int GetFront(Queue* Q) 
{
	if (IsEmpty(Q)) {
		printf("����Ϊ�գ��޶�ͷԪ�أ�\n");
		return -1;  // ����һ������ֵ
	}
	return Q->front->data;  // ���ض�ͷԪ��
}
//�û��鿴����
void InspectQueue(Queue* Q)
{
	if (IsEmpty(Q))
	{
		printf("��ʱû������\n");
		return;
	}
	Node *p = Q->front;
	printf("�������ݣ�");
	while (p!=NULL)
	{
		printf(" %d ", p->data);
		p = p->next;
	}
	printf("\n");
}

