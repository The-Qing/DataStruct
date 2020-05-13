// 顺序表的动态存储
#include<stdio.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // 指向动态开辟的数组
	size_t size;    // 有效数据个数
	size_t capicity;  // 容量空间的大小
}SeqList;

// 基本增删查改  接口
void SeqListInit(SeqList* psl, size_t capacity)		// 顺序表初始化
{
	assert(psl != NULL);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	psl->capicity = 0;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)	// 顺序表销毁
{
	assert(psl != NULL);
	assert(psl->array != NULL);
	free(psl->array);	//释放空间
	psl->size = 0;
	psl->capicity = psl->size = 0;
}

void SeqListPrint(SeqList* psl)// 顺序表打印
{
	assert(psl);
	for (size_t i = 0; i < psl->array; i++)
	{
		printf("%d", psl->array[i]);
	}
	printf("\n");
}
void CheckCapacity(SeqList* psl)//检查空间，如果满了，进行增容
{
	if (psl->array == psl->capicity)
	{
		size_t newcapicity = psl->capicity == 0 ? 4 : psl->capicity * 2;
		psl->array = (SLDataType*)relloc(psl->array, newcapicity * sizeof(SLDataType));
		psl->capicity = newcapicity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)// 顺序表尾插
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)// 顺序表尾删
{
	assert(psl);
	psl->array[psl->size - 1] = 0;
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)// 顺序表头插
{
	assert(psl);
	CheckCapacity(psl);
	for (size_t i = psl->size; i > 0; ++i)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[0] = x;
	psl->size++;
}
void SeqListPopFront(SeqList* psl)// 顺序表头删
{
	assert(psl);
	for (size_t i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)// 顺序表查找
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;	//返回角标
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)// 顺序表在pos位置插入x
{
	assert(psl);
	assert(pos != 0 && pos <= psl->size);
	CheckCapacity(psl);
	for (size_t i = psl->size - 1; i <= (int)pos; i--)
	{
		psl->array[i] = psl->array[i - 1];
	}
	psl->array[pos] = x;
	psl->size++;
}
void SeqListErase(SeqList* psl, size_t pos)// 顺序表删除pos位置的值
{
	assert(pos >= 0 && pos < psl->size);
	for (size_t i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}