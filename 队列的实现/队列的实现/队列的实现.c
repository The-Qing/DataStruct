#include<stdio.h>
#include<assert.h>
// ��ʽ�ṹ����ʾ���� 
typedef  int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* front; //ͷ
	QNode* rear; // β
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q)
{
	q->front = q->rear = (QNode*)malloc(sizeof(QDataType));
	q->front->next = NULL;
}
// ��β����� 
void QueuePush(Queue* q, QDataType data)
{
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	if (temp)
	{
		temp->_data = data;
		temp->next = NULL;
		q->rear->next = temp;
		q->rear = temp;
	}
}
// ��ͷ������ 
void QueuePop(Queue* q)
{
	QNode* temp;
	temp = q->front->next;
	if (q->front->next == NULL)
	{
		free(q->front);
		q->front = q->rear = NULL;
	}
	else
	{
		free(q->front);
		q->front = temp;
	}
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->_data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->_data;
}
// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q)
{
	assert(q);
	QNode* cur = (QNode*)malloc(sizeof(QNode));
	int n = 0;
	while (cur)
	{
		cur = cur->next;
		n++;
	}
	return n;
}
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == NULL) ? 1 : 0;
}
// ���ٶ��� 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* cur = q->front;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}