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
			printf("请输入您要输入的数据:\n");
			scanf("%d", &e);
			EnQueue(&Q, e);
			printf("输入成功\n");
			break;
		case 2:
			x = DeQueue(&Q);
			printf("删除的数据是%d\n",x);
			break;
		case 3:
			InspectQueue(&Q);
			break;
		default:
			printf("无效操作\n");
			break;
		}
		system("pause");
		system("cls");
	}
}
