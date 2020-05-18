#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
//С��
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a; //����
	int _size;
	int _capacity;
}Heap;

// �ѵĹ���
Heap* HeapCreate(Heap* hp, HPDataType* a, int n)
{
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}
	return hp;
}
// �ѵ�����
void HeapDestory(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->_size = 0;
	hp->_a = NULL;
}
// �ѵĲ���(��β���룩
void HeapPush(Heap* hp, HPDataType x)
{
	//�ռ䲻��ʱ����
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//���ϵ���Ϊ��
	Adjustup(hp->_a, hp->_size - 1);
}
// �ѵ�ɾ��(ͷβ����,ɾβ�����µ���)
void HeapPop(Heap* hp)
{
	int tmp = hp->_a[0];
	hp->_a = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;

	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

// ��������ж�����
void HeapSort(int* a, int n)
{
	for (int i = (n - 2) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;
	while (end>0)
	{
		int tmp = a[end];
		a[end] = a[0];
		a[0] = tmp;

		AdjustDown(a, end, 0);
		--end;
	}
}

// TopK���⣺�ҳ�N�����������/��С��ǰK�����⡣
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k)
{
	//��ǰK�����ݱ���
	HPDataType* arr = (HPDataType*)malloc(sizeof(HPDataType)*k);
	for (int i = 0; i < k; i++)
	{
		arr[i] = a[i];
	}
	//����(����Ϊk)
	for (int i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(arr, k, i);
	}

	for (int i = k; i < n; i++)
	{
		if (arr[0] < a[i])
		{
			arr[0] = a[i];
			AdjustDown(arr, 0, k);
		}
	}
	a = arr;

}
void TestTopk();

void AdjustDown(int* a, int n, int root)//(С��) ��������Ҳ����ΪС��
{
	int child = root * 2 + 1;
	int parent = root;
	while (child < n)
	{
		//�ҵ�С�ĺ���
		if ((child + 1 < n) && (a[child + 1]<a[child]))   //���Ӵ����Һ���
		{
			++child;
		}
		//����
		if (a[child]<a[parent])
		{
			int tmp = a[child];
			a[child] = a[parent];
			a[parent] = tmp;
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void Adjustup(int* a, int child) //С��
{
	while (1)
	{
		int parent = (child - 1) / 2;
		if (child == 0)
		{
			break;
		}
		if (a[parent] > a[child])
		{
			break;
		}
		int tmp = a[child];
		a[child] = a[parent];
		a[parent] = tmp;

		child = parent;

	}
}