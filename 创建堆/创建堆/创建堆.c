#include<stdio.h>
#include<assert.h>
#include<malloc.h>
#include<stdlib.h>
//小堆
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a; //数组
	int _size;
	int _capacity;
}Heap;

// 堆的构建
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
// 堆的销毁
void HeapDestory(Heap* hp)
{
	if (hp == NULL)
		return;
	hp->_size = 0;
	hp->_a = NULL;
}
// 堆的插入(从尾插入）
void HeapPush(Heap* hp, HPDataType x)
{
	//空间不够时增容
	if (hp->_size == hp->_capacity)
	{
		size_t newcapacity = hp->_capacity * 2;
		hp->_a = (HPDataType*)realloc(sizeof(HPDataType)*newcapacity);
		hp->_capacity = newcapacity;
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	//向上调整为堆
	Adjustup(hp->_a, hp->_size - 1);
}
// 堆的删除(头尾交换,删尾，向下调整)
void HeapPop(Heap* hp)
{
	int tmp = hp->_a[0];
	hp->_a = hp->_a[hp->_size - 1];
	hp->_a[hp->_size - 1] = tmp;

	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}
// 堆的数据个数
int HeapSize(Heap* hp)
{
	return hp->_size;
}
// 堆的判空
int HeapEmpty(Heap* hp)
{
	return hp->_size == 0 ? 1 : 0;
}

// 对数组进行堆排序
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

// TopK问题：找出N个数里面最大/最小的前K个问题。
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k)
{
	//将前K个数据保存
	HPDataType* arr = (HPDataType*)malloc(sizeof(HPDataType)*k);
	for (int i = 0; i < k; i++)
	{
		arr[i] = a[i];
	}
	//建堆(个数为k)
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

void AdjustDown(int* a, int n, int root)//(小堆) 左右子树也必须为小堆
{
	int child = root * 2 + 1;
	int parent = root;
	while (child < n)
	{
		//找到小的孩子
		if ((child + 1 < n) && (a[child + 1]<a[child]))   //左孩子大于右孩子
		{
			++child;
		}
		//调整
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
void Adjustup(int* a, int child) //小堆
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