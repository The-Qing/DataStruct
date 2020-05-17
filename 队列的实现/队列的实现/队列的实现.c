#include<stdio.h>
#include<assert.h>
// 链式结构：表示队列 
typedef  int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* front; //头
	QNode* rear; // 尾
}Queue;

// 初始化队列 
void QueueInit(Queue* q)
{
	q->front = q->rear = (QNode*)malloc(sizeof(QDataType));
	q->front->next = NULL;
}
// 队尾入队列 
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
// 队头出队列 
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
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
	return q->front->_data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q)
{
	assert(q);
	return q->rear->_data;
}
// 获取队列中有效元素个数 
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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == NULL) ? 1 : 0;
}
// 销毁队列 
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