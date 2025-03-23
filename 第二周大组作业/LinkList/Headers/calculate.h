#pragma once
//�������Ľڵ�ṹ
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;
//������ջ
typedef struct {
    StackNode* top;//ջ��
} LinkStack;

void InitStack(LinkStack* S);
int IsEmpty(LinkStack* S);
void Getin(LinkStack* S, char ch);
char PutOut(LinkStack* S);
char GetTop(LinkStack* S);
int IsOperator(char ch);
int GetPriority(char ch);
void InfixToPostfix(char* infix, char* postfix);
int CalculatePostfix(char* postfix);

