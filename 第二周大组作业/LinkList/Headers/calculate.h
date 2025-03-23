#pragma once
//定义链的节点结构
typedef struct StackNode {
    char data;
    struct StackNode* next;
} StackNode;
//定义链栈
typedef struct {
    StackNode* top;//栈顶
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

