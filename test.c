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
}

//��ֵ����
int Locate(SeqList* s, int x)
{
    int length = s->length;
    for (int i = 0; i < length; i++)
    {
        if (s->data[i] == x)
        {
            return i;
        }
        break;
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
    SeqList list;
    initSeqList(&list);
    if (Empty(&list))
    {
        printf("��ʼ���ɹ�\n");
    }
    printf("��˳���ֵ\n");
    CreatList(&list, a, 5);
    PrintList(&list);
    return 0;
}