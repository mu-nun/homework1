#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include < stdbool.h >

#include "calculate.h"

int main()
{
    char infix[100], postfix[100];
    printf("����10���ڵļӼ��˳�\n");
    printf("�������: ");
    scanf("%s", infix);

    InfixToPostfix(infix, postfix);
    printf("��Ӧ�ĺ�׺���ʽΪ: %s\n", postfix);

    int result = CalculatePostfix(postfix);
    printf("���: %d\n", result);

	return 0;
}

