#include<stdio.h>
#include<assert.h>
typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

// ��̬����һ���ڵ�
SListNode* BuySListNode(SLTDateType x)
{
	SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
	newNode->data = x;
	newNode->next = NULL;

	return newNode;
}
// �������ӡ
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
// ������β��
void SListPushBack(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);
	if (*pplist == NULL)	//�ǿյĻ�ֱ�Ӳ���
	{
		*pplist = newNode;
	}
	else					//��Ϊ��
	{
		SListNode* tail = *pplist;			//tail �������һ���ڵ�
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newNode;
	}
}
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	SListNode* newNode = BuySListNode(x);	//����һ���ڵ�
	newNode->next = *pplist;
	*pplist = newNode;

}
// �������βɾ
void SListPopBack(SListNode** pplist)		//3���������  ֻ��һ���ڵ�  �ж���ڵ�
{
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->next == NULL)	//(*pplist) ����Ϊ -> Ҳ���ڽ����� 
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
// ������ͷɾ
void SListPopFront(SListNode** pplist)
{
	SListNode* cur = *pplist;
	*pplist = (*pplist)->next;
	free(cur);
}

// ���������
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
// ��������posλ��֮�����x
// ����˼��Ϊʲô����posλ��֮ǰ���룿
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
	SListNode*  newNode;
	SListNode* cur = pos;
	cur = cur->next;
	pos->next = newNode;
	newNode->next = cur;
}
// ������ɾ��posλ��֮���ֵ    ֻɾpos��һ������
// ����˼��Ϊʲô��ɾ��posλ�ã�
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
// �����������
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