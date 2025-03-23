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
    printf("计算10以内的加减乘除\n");
    printf("输入计算: ");
    scanf("%s", infix);

    InfixToPostfix(infix, postfix);
    printf("对应的后缀表达式为: %s\n", postfix);

    int result = CalculatePostfix(postfix);
    printf("结果: %d\n", result);

	return 0;
}

