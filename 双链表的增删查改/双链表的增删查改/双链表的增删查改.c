#include<stdio.h>
#include<assert.h>
// ��ͷ+˫��+ѭ��������ɾ���ʵ��
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// �������������ͷ���.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->prev = NULL;
	head->next = NULL;
}
// ˫����������
void ListDestory(ListNode* plist)
{
	ListNode* cur = plist->next;
	ListNode* del = NULL;
	while (cur != plist)
	{
		del = cur;
		cur = cur->next;
		free(del);
	}
	free(plist);
}
// ˫�������ӡ
void ListPrint(ListNode* plist)
{
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//�����½ڵ�
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
// ˫������β��
void ListPushBack(ListNode* plist, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = plist->prev;

	cur->next = newnode;
	newnode->prev = cur;
	plist->prev = newnode;
	newnode->next = plist;

}
// ˫������βɾ
void ListPopBack(ListNode* plist)
{
	ListNode* cur = plist->prev;
	ListNode* temp = cur->prev;

	free(cur);
	plist->prev = temp;
	temp->next = plist;
}
// ˫������ͷ��
void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* temp = plist->next;

	plist->next = newnode;
	newnode->prev = plist;
	newnode->next = temp;
	temp->prev = newnode;
}
// ˫������ͷɾ
void ListPopFront(ListNode* plist)
{
	ListNode* cur = plist->next->next;
	free(plist->next);
	plist->next = cur;
	cur->prev = plist;
}
// ˫���������
ListNode* ListFind(ListNode* plist, LTDataType x)
{
	ListNode* cur = plist->next;
	while (cur != plist)
	{
		if (cur->data == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = pos->prev;

	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = pos;
	pos->prev = newnode;

}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos)
{
	ListNode* cur = pos->next;
	ListNode* Prev = pos->prev;

	Prev->next = cur;
	cur->prev = Prev;
	free(pos);
}