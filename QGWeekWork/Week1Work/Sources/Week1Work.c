#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>
#include < stdbool.h >

//����һ�����������ڴ洢����
typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;
//����һ��˫���������ڴ洢����
typedef struct DNode
{
    int data;
    struct DNode* prior, * next;
}DNode;
bool InitList(LNode* L)//��ʼ��������
{
    L = (LNode*)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}
bool InitDLinkList(DNode* L)//��ʼ��˫������
{
    L = (DNode*)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}
LNode* GetElem(LNode* L, int i)//��λ���ѯ
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
LNode* LocateElem(LNode* L, int e)//��ֵ��ѯ
{
    LNode* p = L->next;
    while (p != NULL && p->data != e)
    {
        p = p->next;
    }
    return p;
}
bool ListInsert(LNode* L, int i, int e)//�����i�����
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
bool ListDelete(LNode* L, int i, int* e)//ɾ����i�����
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
    printf("��ѡ����Ҫ���еĲ�����\n");
    printf("1.���������\n");
    printf("2.˫���������\n");
}
void LNodeMenu()
{
    printf("��ѡ����Ҫ���еĲ�����\n");
    printf("1.��������\n");
    printf("2.ɾ������\n");
    printf("3.��ʾ��������\n");
    printf("4.�˳�\n");
}
bool LNodeInput(LNode* L)
{
    int i = 0;
    int e = 0;
    printf("��������Ҫ����ڼ������: ");
    scanf("%d", &i);
    printf("��������Ҫ�������: ");
    scanf("%d", &e);
    if (ListInsert(L, i, e) == false)
    {
        printf("����ʧ��\n");
        return false;
    }
    return true;
}
bool LNodeDelete(LNode* L)
{
    int i = 0;
    int e;
    printf("��������Ҫɾ���ڼ������:");
    scanf("%d", &i);
    if (ListDelete(L, i, &e) == false)
    {
        printf("ɾ��ʧ��");
        return false;
    }
    else
    {
        printf("ɾ���ɹ���ɾ����ֵ�ǣ�%d", e);
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
            printf("�� %d ������������ %d \n", i, p->data);
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
                printf("����ɹ�");
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
            printf("ָ����Ч\n");
            break;
        }
        system("pause");
        system("cls");
    }
}
bool DeleteDNode(DNode* p)//˫������ɾ��p������Ľ��
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
DNode* GetDNode(DNode* D, int i)//��λ���ѯ
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
    printf("��������Ҫ�������: ");
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
    printf("��������Ҫɾ���ڼ������:");
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
            printf("�� %d ������������ %d \n", i, p->data);
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
                printf("����ɹ�\n");
            else
                printf("����ʧ��\n");
            break;
        case 2:
            if (DNodeDelete)
                printf("ɾ���ɹ�\n");
            else
                printf("ɾ��ʧ��\n");
            break;
        case 3:
            showDNode(D);
            break;
        case 4:
            return;
            break;
        default:
            printf("ָ����Ч\n");
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
            printf("ָ����Ч\n");
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}







