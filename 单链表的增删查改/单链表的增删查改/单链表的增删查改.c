#include<stdio.h>
#include<assert.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
// 单链表打印
void SListPrint(SListNode* plist)
{
	SListNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)	//是空的话直接插入
	{
		*pplist = newNode;
	}
	else					//不为空
	{
		SListNode* tail = *pplist;			//tail 保存最后一个节点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);	//申请一个节点
	newNode->next = *pplist;
	*pplist = newNode;

}
// 单链表的尾删
void SListPopBack(SListNode** pplist)		//3种情况：空  只有一个节点  有多个节点
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)	//(*pplist) 是因为 -> 也属于解引用 
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		SListNode* prev = NULL;
		SListNode* tail = *pplist;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		if (prev != NULL)
			prev->next = NULL;
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* cur = *pplist;
	*pplist = (*pplist)->next;
	free(cur);
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
	SListNode* cur = plist;
	for (cur; cur != NULL; cur->next)
	{
		if (cur->data == x)
		{
			return cur;
		}
	}
	return NULL;
}
// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode*  newNode;
	SListNode* cur = pos;
	cur = cur->next;
	pos->next = newNode;
	newNode->next = cur;
}
// 单链表删除pos位置之后的值    只删pos后一个数据
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
	SListNode* cur = pos;
	SListNode* prev;
	if (cur->next == NULL)
	{
		return;
	}
	else
	{

	}

}
// 单链表的销毁
void SListDestory(SListNode* plist)
{
	assert(plist);
	SListNode*  cur = NULL;
	SListNode*  del = NULL;
	cur = plist;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->next;
		free(del);
		del = NULL;
	}
	plist = NULL;
}