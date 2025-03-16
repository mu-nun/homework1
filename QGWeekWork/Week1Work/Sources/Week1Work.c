#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include < stdbool.h >

//定义一个单链表，用于存储数据
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;
//定义一个双向链表，用于存储数据
typedef struct DNode
{
    int data;
    struct DNode* prior, * next;
}DNode;
bool InitList(LNode* L)//初始化单链表
{
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
bool InitDLinkList(DNode* L)//初始化双向链表
{
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
LNode* GetElem(LNode* L, int i)//按位序查询
{
    if (i < 0)
    {
        return NULL;
    }
    LNode* p;
    int j = 0;
    p = L;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
LNode* LocateElem(LNode* L, int e)//按值查询
{
    LNode* p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
bool ListInsert(LNode* L, int i, int e)//插入第i个结点
{
    LNode* p = GetElem(L, i - 1);
    if (p == NULL)
        return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
bool ListDelete(LNode* L, int i, int* e)//删除第i个结点
{
    LNode* p = GetElem(L, i - 1);
    if (p == NULL)
        return false;
    LNode* q = p->next;
    e = q->data;
    p->next = q->next;
    free(q);
    return true;
}
void menu()
{
    printf("请选择您要进行的操作：\n");
    printf("1.单链表操作\n");
    printf("2.双向链表操作\n");
}
void LNodeMenu()
{
    printf("请选择您要进行的操作：\n");
    printf("1.插入数据\n");
    printf("2.删除数据\n");
    printf("3.显示所有数据\n");
    printf("4.退出\n");
}
bool LNodeInput(LNode* L)
{
    int i = 0;
    int e = 0;
    printf("请输入您要插入第几个结点: ");
    scanf("%d", &i);
    printf("请输入您要插入的数: ");
    scanf("%d", &e);
    if (ListInsert(L, i, e) == false)
    {
        printf("插入失败\n");
        return false;
    }
    return true;
}
bool LNodeDelete(LNode* L)
{
    int i = 0;
    int e;
    printf("请输入您要删除第几个结点:");
    scanf("%d", &i);
    if (ListDelete(L, i, &e) == false)
    {
        printf("删除失败");
        return false;
    }
    else
    {
        printf("删除成功，删除的值是：%d", e);
        return true;
    }
}
void showLNode(LNode* L)
{
    int i = 1;
    while (1)
    {
        LNode* p = GetElem(L, i);
        if (p != NULL)
            printf("第 %d 个结点的数据是 %d \n", i, p->data);
        else
            break;
        i++;
    }
    return;
}
void LNodeUse(LNode* L)
{
    system("cls");
    while (1)
    {
        LNodeMenu();
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            if (LNodeInput(L))
                printf("插入成功");
            break;
        case 2:
            LNodeDelete(L);
            break;
        case 3:
            showLNode(L);
            break;
        case 4:
            return;
            break;
        default:
            printf("指令无效\n");
            break;
        }
        system("pause");
        system("cls");
    }
}
bool DeleteDNode(DNode* p)//双向链表删除p结点后面的结点
{
    if (p == NULL)
        return false;
    DNode* q = p->next;
    if (q == NULL)
        return false;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);
    return true;
}
DNode* GetDNode(DNode* D, int i)//按位序查询
{
    if (i < 0)
    {
        return NULL;
    }
    DNode* p;
    int j = 0;
    p = D;
    while (p != NULL && j < i)
    {
        p = p->next;
        j++;
    }
    return p;
}
bool DNodeInput(DNode* D)
{
    DNode* p = D;
    int e = 0;
    printf("请输入您要插入的数: ");
    scanf("%d", &e);
    while (p->next != NULL)
    {
        p = p->next;
    }
    DNode* s = (DNode*)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    s->prior = p;
    p->next = s;
    return true;
}
bool DNodeDelete(DNode* D)
{
    int i = 0;
    printf("请输入您要删除第几个结点:");
    scanf("%d", &i);
    DNode* p = GetDNode(D, i - 1);
    if (p == NULL)
        return false;
    else
    {
        if (DeleteDNode(p))
            return true;
    }
}
void showDNode(DNode* D)
{
    int i = 1;
    while (1)
    {
        DNode* p = GetDNode(D, i);
        if (p != NULL)
            printf("第 %d 个结点的数据是 %d \n", i, p->data);
        else
            break;
        i++;
    }
    return;
}
void DNodeUse(DNode* D)
{
    while (1)
    {
        LNodeMenu();
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            if (DNodeInput(D))
                printf("插入成功\n");
            else
                printf("插入失败\n");
            break;
        case 2:
            if (DNodeDelete)
                printf("删除成功\n");
            else
                printf("删除失败\n");
            break;
        case 3:
            showDNode(D);
            break;
        case 4:
            return;
            break;
        default:
            printf("指令无效\n");
            break;
        }
        system("pause");
        system("cls");
    }
}
int main()
{
    LNode* L;
    L = (LNode*)malloc(sizeof(LNode));
    InitList(L);
    DNode* D;
    D = (DNode*)malloc(sizeof(DNode));
    InitDLinkList(D);
    while (1)
    {
        menu();
        int input;
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            LNodeUse(L);
            break;
        case 2:
            DNodeUse(D);
            break;
        default:
            printf("指令无效\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}







