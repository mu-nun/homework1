#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculate.h"
// 初始化栈
void InitStack(LinkStack* S)
{
    S->top = NULL;
}
//判断栈是否为空
int IsEmpty(LinkStack* S)
{
    return S->top == NULL;
}
//入栈
void Getin(LinkStack* S,char ch)
{
    StackNode* newNode= (StackNode*)malloc(sizeof(StackNode));
    newNode->data = ch;
    newNode->next = S->top;
    S->top = newNode;
}
//出栈
char PutOut(LinkStack* S)
{
    if (IsEmpty(S))
        return '\0';
    StackNode* temp = S->top;
    char ch = temp->data;
    S->top = temp->next;
    free(temp);
    return ch;
}
// 获取栈顶元素
char GetTop(LinkStack* S) 
{
    if (IsEmpty(S)) {
        return '\0';
    }
    return S->top->data;
}
// 判断当前字符是否为运算符
int IsOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// 获取运算符的优先级 * / 的优先级更高
int GetPriority(char ch)
{
    if (ch == '+' || ch == '-') {
        return 1;
    }
    else if (ch == '*' || ch == '/') {
        return 2;
    }
    return 0;
}
// 中缀表达式转后缀表达式
void InfixToPostfix(char* infix, char* postfix)
//infix：输入的中缀表达式字符串。
//postfix：输出的后缀表达式字符串
{
    LinkStack S; //创建一个链栈 S，并调用 InitStack 函数初始化栈,用于存放运算符和左括号
    InitStack(&S);
    int i = 0, j = 0;//i用于遍历中缀表达式 infix  j用于构建后缀表达式 postfix
    char ch;//处理当前字符

    while ((ch = infix[i++]) != '\0')//逐个读取中缀表达式中的字符，直到字符串结束（\0）。
    {
        if (isdigit(ch)) 
        {
            postfix[j++] = ch;
        }//判断是否为数字字符，数字字符会直接转到postfix中
        else if (ch == '(') 
        {
            Getin(&S, ch);
        }//左括号入栈
        else if (ch==')')//处理右括号
        {
            while (GetTop(&S) != '(')
            {
                postfix[j++] = PutOut(&S);//持续出栈，直到遇到(为止
            }
            PutOut(&S);//弹出(
        }
        else if (IsOperator(ch))//处理运算符
        {
            while (!IsEmpty(&S) && GetPriority(GetTop(&S)) >= GetPriority(ch)) //优先级判断,如果遇到优先级高的，就将优先级高的运算符出栈
            {
                postfix[j++] = PutOut(&S);
            }
            Getin(&S, ch);
        }
    }
    while (!IsEmpty(&S)) //处理栈中剩下的运算符,将其放入到后缀表达式字符串postfix中
    {
        postfix[j++] = PutOut(&S);
    }
    postfix[j] = '\0';//结束字符串
}
// 计算后缀表达式
int CalculatePostfix(char* postfix) 
{
    LinkStack S;
    InitStack(&S);
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            Getin(&S, ch - '0');//将数字入栈
        }
        else if (IsOperator(ch)) {
            int b = PutOut(&S);//相邻的两个数字出栈
            int a = PutOut(&S);
            int result;
            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            }
            Getin(&S, result);//将结果重新入栈
        }
    }

    return PutOut(&S);//返回最终结果
}

