#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calculate.h"
// ��ʼ��ջ
void InitStack(LinkStack* S)
{
    S->top = NULL;
}
//�ж�ջ�Ƿ�Ϊ��
int IsEmpty(LinkStack* S)
{
    return S->top == NULL;
}
//��ջ
void Getin(LinkStack* S,char ch)
{
    StackNode* newNode= (StackNode*)malloc(sizeof(StackNode));
    newNode->data = ch;
    newNode->next = S->top;
    S->top = newNode;
}
//��ջ
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
// ��ȡջ��Ԫ��
char GetTop(LinkStack* S) 
{
    if (IsEmpty(S)) {
        return '\0';
    }
    return S->top->data;
}
// �жϵ�ǰ�ַ��Ƿ�Ϊ�����
int IsOperator(char ch)
{
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}
// ��ȡ����������ȼ� * / �����ȼ�����
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
// ��׺���ʽת��׺���ʽ
void InfixToPostfix(char* infix, char* postfix)
//infix���������׺���ʽ�ַ�����
//postfix������ĺ�׺���ʽ�ַ���
{
    LinkStack S; //����һ����ջ S�������� InitStack ������ʼ��ջ,���ڴ���������������
    InitStack(&S);
    int i = 0, j = 0;//i���ڱ�����׺���ʽ infix  j���ڹ�����׺���ʽ postfix
    char ch;//����ǰ�ַ�

    while ((ch = infix[i++]) != '\0')//�����ȡ��׺���ʽ�е��ַ���ֱ���ַ���������\0����
    {
        if (isdigit(ch)) 
        {
            postfix[j++] = ch;
        }//�ж��Ƿ�Ϊ�����ַ��������ַ���ֱ��ת��postfix��
        else if (ch == '(') 
        {
            Getin(&S, ch);
        }//��������ջ
        else if (ch==')')//����������
        {
            while (GetTop(&S) != '(')
            {
                postfix[j++] = PutOut(&S);//������ջ��ֱ������(Ϊֹ
            }
            PutOut(&S);//����(
        }
        else if (IsOperator(ch))//���������
        {
            while (!IsEmpty(&S) && GetPriority(GetTop(&S)) >= GetPriority(ch)) //���ȼ��ж�,����������ȼ��ߵģ��ͽ����ȼ��ߵ��������ջ
            {
                postfix[j++] = PutOut(&S);
            }
            Getin(&S, ch);
        }
    }
    while (!IsEmpty(&S)) //����ջ��ʣ�µ������,������뵽��׺���ʽ�ַ���postfix��
    {
        postfix[j++] = PutOut(&S);
    }
    postfix[j] = '\0';//�����ַ���
}
// �����׺���ʽ
int CalculatePostfix(char* postfix) 
{
    LinkStack S;
    InitStack(&S);
    int i = 0;
    char ch;

    while ((ch = postfix[i++]) != '\0') {
        if (isdigit(ch)) {
            Getin(&S, ch - '0');//��������ջ
        }
        else if (IsOperator(ch)) {
            int b = PutOut(&S);//���ڵ��������ֳ�ջ
            int a = PutOut(&S);
            int result;
            switch (ch) {
            case '+': result = a + b; break;
            case '-': result = a - b; break;
            case '*': result = a * b; break;
            case '/': result = a / b; break;
            }
            Getin(&S, result);//�����������ջ
        }
    }

    return PutOut(&S);//�������ս��
}

