#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MaxSize 1000

//����˳���
typedef struct {
    int data[100];
    int length;
}SeqList;

//��ʼ��˳���
void initSeqList(SeqList* s)
{
    s->length = 0;
}

//����˳���
bool CreatList(SeqList* s, int a[], int n)
{
    if (n > MaxSize)
    {
        printf("�ռ䲻�����޷�����˳���\n");
    }
    for (int k = 0; k < n; k++)
    {
        s->data[k] = a[k];
    }
    s->length = n;
    return true;
}

//�п�˳���
bool Empty(SeqList* s)
{
    if (s->length == 0)
    {
        return true;
    }
    else
        return false;
}

//��˳���ĳ���
int Length(SeqList* s)
{
    return s->length;
}

//��������
void PrintList(SeqList* s)
{
    for (int i = 0; i < s->length; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

//��ֵ����
int Locate(SeqList* s, int x)
{
    int len = s->length;
    for (int i = 0; i < len; i++)
    {
        if (s->data[i] == x)
        {
            return i;
            break;
        }
    }
}

//��λ����
int Get(SeqList* s, int x)
{
    if (x > MaxSize || x < 0)
    {
        printf("����λ�÷Ƿ���\n");
    }
    if (x == 1)
    {
        return s->data[0];
    }
    else
        return s->data[x - 1];
}

//�������
bool Insert(SeqList* s, int x, int l)
{
    if (l > MaxSize || l < 0)
    {
        printf("����λ�÷Ƿ���\n");
        return false;
    }
    for (int i = s->length; i > l; i--)
    {
        s->data[i] = s->data[i - 1];
    }
    s->data[l] = x;
    s->length++;
    return true;
}

//ɾ������
bool Delete(SeqList* s, int l)
{
    if (l < 0 || l >= s->length)
    {
        printf("ɾ���±겻����");
        return false;
    }
    for (int index = l + 1; index < s->length; index++)
    {
        int j = l;
        s->data[j] = s->data[index];
        j++;
    }
    s->length--;
    return true;
}

//�޸Ĳ���
bool Modify(SeqList* s, int l, int x)
{
    if (l<0 || l>s->length)
    {
        printf("error\n");
        return false;
    }
    s->data[l] = x;
    return true;
}

int main()
{
    int a[5] = { 1,2,3,4,5 };
    int b = 0;
    int c = 0;
    int d = 0;
    int i = 0;
    int x = 0;
    int y = 0;
    int k = 0;
    SeqList list;
    initSeqList(&list);
    if (Empty(&list))
    {
        printf("��ʼ���ɹ�\n");
    }
    printf("��˳���ֵ\n");
    CreatList(&list, a, 5);
    PrintList(&list);
    while (1)
    {
        printf("��ѡ��Գ������������\n");
        printf("1.��������\n");
        printf("2.��ֵ����\n");
        printf("3.��λ����\n");
        printf("4.�������\n");
        printf("5.ɾ������\n");
        scanf("%d", &i);
        if (i == 1)
        {
            PrintList(&list);
            printf("���������˳�������1���˳� or 0������\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 2)
        {
            printf("������Ҫ���ҵ�ֵ\n");
            scanf("%d", &x);
            printf("%d\n", Locate(&list, x));
            printf("���������˳�������1���˳� or 0������\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 3)
        {
            printf("������Ҫ���ҵ�λ\n");
            scanf("%d", &y);
            printf("%d\n", Get(&list, y));
            printf("���������˳�������1���˳� or 0������\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 4)
        {
            printf("������Ҫ�����ֵ��λ��\n");
            scanf("&d &d", &c, &b);
            Insert(&list, c, b);
            printf("���������˳�������1���˳� or 0������\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 5)
        {
            printf("������Ҫɾ����λ\n");
            scanf("%d", &d);
            Delete(&list, d);
            PrintList(&list);
            printf("���������˳�������1���˳� or 0������\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
    }
    return 0;
}