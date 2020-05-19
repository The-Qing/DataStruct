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
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树  #为空格
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
// 二叉树销毁
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
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}
// 二叉树叶子节点个数
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
// 二叉树第k层节点个数
int BinaryTreeLevelkSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return BinaryTreeLevelkSize(root->_left, k - 1) + BinaryTreeLevelkSize(root->_right, k - 1);
}
// 二叉树查找值为x的节点
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
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
	if (root == NULL)
		return NULL;
	printf("%d", root->_data);
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{

	if (root == NULL)
		return NULL;
	BinaryTreePostOrder(root->_left);
	printf("%d", root->_data);
	BinaryTreePostOrder(root->_right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{

	if (root == NULL)
		return NULL;
	BinaryTreePostOrder(root->_left);
	BinaryTreePostOrder(root->_right);
	printf("%d", root->_data);
}

// 层序遍历   构建队列 每次将根节点和左右孩子存入队列->将front弹出 递归 

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
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return (q->front == NULL) ? 1 : 0;
}
//层序遍历   构建队列 每次将根节点和左右孩子存入队列->将front弹出 递归 
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