#include<stdio.h>
#include<assert.h>
// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

// 创建返回链表的头结点.
ListNode* ListCreate()
{
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->prev = NULL;
	head->next = NULL;
}
// 双向链表销毁
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
// 双向链表打印
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
//创建新节点
ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
// 双向链表尾插
void ListPushBack(ListNode* plist, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = plist->prev;

	cur->next = newnode;
	newnode->prev = cur;
	plist->prev = newnode;
	newnode->next = plist;

}
// 双向链表尾删
void ListPopBack(ListNode* plist)
{
	ListNode* cur = plist->prev;
	ListNode* temp = cur->prev;

	free(cur);
	plist->prev = temp;
	temp->next = plist;
}
// 双向链表头插
void ListPushFront(ListNode* plist, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* temp = plist->next;

	plist->next = newnode;
	newnode->prev = plist;
	newnode->next = temp;
	temp->prev = newnode;
}
// 双向链表头删
void ListPopFront(ListNode* plist)
{
	ListNode* cur = plist->next->next;
	free(plist->next);
	plist->next = cur;
	cur->prev = plist;
}
// 双向链表查找
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
// 双向链表在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	ListNode* newnode = BuyListNode(x);
	ListNode* cur = pos->prev;

	cur->next = newnode;
	newnode->prev = cur;
	newnode->next = pos;
	pos->prev = newnode;

}
// 双向链表删除pos位置的节点
void ListErase(ListNode* pos)
{
	ListNode* cur = pos->next;
	ListNode* Prev = pos->prev;

	Prev->next = cur;
	cur->prev = Prev;
	free(pos);
}