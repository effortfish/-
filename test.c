#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdbool.h>
#define MaxSize 1000

//定义顺序表
typedef struct {
    int data[100];
    int length;
}SeqList;

//初始化顺序表
void initSeqList(SeqList* s)
{
    s->length = 0;
}

//建立顺序表
bool CreatList(SeqList* s, int a[], int n)
{
    if (n > MaxSize)
    {
        printf("空间不够，无法建立顺序表。\n");
    }
    for (int k = 0; k < n; k++)
    {
        s->data[k] = a[k];
    }
    s->length = n;
    return true;
}

//判空顺序表
bool Empty(SeqList* s)
{
    if (s->length == 0)
    {
        return true;
    }
    else
        return false;
}

//求顺序表的长度
int Length(SeqList* s)
{
    return s->length;
}

//遍历操作
void PrintList(SeqList* s)
{
    for (int i = 0; i < s->length; i++)
    {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

//按值查找
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

//按位查找
int Get(SeqList* s, int x)
{
    if (x > MaxSize || x < 0)
    {
        printf("查找位置非法。\n");
    }
    if (x == 1)
    {
        return s->data[0];
    }
    else
        return s->data[x - 1];
}

//插入操作
bool Insert(SeqList* s, int x, int l)
{
    if (l > MaxSize || l < 0)
    {
        printf("查找位置非法。\n");
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

//删除操作
bool Delete(SeqList* s, int l)
{
    if (l < 0 || l >= s->length)
    {
        printf("删除下标不存在");
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

//修改操作
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
        printf("初始化成功\n");
    }
    printf("给顺序表赋值\n");
    CreatList(&list, a, 5);
    PrintList(&list);
    while (1)
    {
        printf("请选择对程序操作？？？\n");
        printf("1.遍历操作\n");
        printf("2.按值查找\n");
        printf("3.按位查找\n");
        printf("4.插入操作\n");
        printf("5.删除操作\n");
        scanf("%d", &i);
        if (i == 1)
        {
            PrintList(&list);
            printf("继续或者退出？？？1：退出 or 0：继续\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 2)
        {
            printf("请输入要查找的值\n");
            scanf("%d", &x);
            printf("%d\n", Locate(&list, x));
            printf("继续或者退出？？？1：退出 or 0：继续\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 3)
        {
            printf("请输入要查找的位\n");
            scanf("%d", &y);
            printf("%d\n", Get(&list, y));
            printf("继续或者退出？？？1：退出 or 0：继续\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 4)
        {
            printf("请输入要插入的值和位置\n");
            scanf("&d &d", &c, &b);
            Insert(&list, c, b);
            printf("继续或者退出？？？1：退出 or 0：继续\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
        if (i == 5)
        {
            printf("请输入要删除的位\n");
            scanf("%d", &d);
            Delete(&list, d);
            PrintList(&list);
            printf("继续或者退出？？？1：退出 or 0：继续\n");
            scanf("%d", &k);
            if (k == 1)
                break;
        }
    }
    return 0;
}