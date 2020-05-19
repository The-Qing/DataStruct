#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������  #Ϊ�ո�
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi)
{
	if (a[*pi] == '#')
	{
		*pi++;
		return NULL;
	}
	BTNode* root = (BTNode*)malloc(sizeof(BTNode));
	root->_left = NULL;
	root->_right = NULL;
	root->_data = a[*pi];
	(*pi)++;
	root->_left = BinaryTreeCreate(a, n, pi);
	root->_right = BinaryTreeCreate(a, n, pi);
	return root;
}
// ����������
void BinaryTreeDestory(BTNode* root)
{
	if (root)
	{
		BinaryTreeDestory(root->_left);
		BinaryTreeDestory(root->_right);
		free(root);
		root = NULL;
	}
}
// �������ڵ����
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else
	{
		if ((root->_left == NULL) && (root->_right == NULL))
			return 1;
		else
			return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
	}
}
// ��������k��ڵ����
int BinaryTreeLevelkSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelkSize(root->_left, k - 1) + BinaryTreeLevelkSize(root->_right, k - 1);
}
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	BTNode* ret;
	if (!root)
		return NULL;
	if (root->_data == x)
		return root;
	ret = BinaryTreeFind(root->_left, x);
	if (ret) return ret;
	ret = BinaryTreeFind(root->_right, x);
	if (ret) return ret;

	return NULL;
}
// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return NULL;
	printf("%d", root->_data);
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
}
// �������������
void BinaryTreeInOrder(BTNode* root)
{

	if (root == NULL)
		return NULL;
	BinaryTreePostOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreePostOrder(root->_right);
}
// �������������
void BinaryTreePostOrder(BTNode* root)
{

	if (root == NULL)
		return NULL;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d", root->_data);
}

// �������   �������� ÿ�ν����ڵ�����Һ��Ӵ������->��front���� �ݹ� 

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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == NULL) ? 1 : 0;
}
//�������   �������� ÿ�ν����ڵ�����Һ��Ӵ������->��front���� �ݹ� 
void BinaryTreeLevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
		QueuePush(&q, root->_data);
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		printf("%c", front->_data);
		if (root->_left)
			QueuePush(&q, root->_left->_data);
		if (root->_right)
			QueuePush(&q, root->_right->_data);
	}
}