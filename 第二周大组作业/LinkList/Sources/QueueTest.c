#include "Queue.h"
int main()
{
	Queue Q;
	int e;
	int x;
	InitQueue(&Q);
	int input = 0;
	while (1)
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��������Ҫ���������:\n");
			scanf("%d", &e);
			EnQueue(&Q, e);
			printf("����ɹ�\n");
			break;
		case 2:
			x = DeQueue(&Q);
			printf("ɾ����������%d\n",x);
			break;
		case 3:
			InspectQueue(&Q);
			break;
		default:
			printf("��Ч����\n");
			break;
		}
		system("pause");
		system("cls");
	}
}
