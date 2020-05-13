// ˳���Ķ�̬�洢
#include<stdio.h>
#include<assert.h>
typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* array; // ָ��̬���ٵ�����
	size_t size;    // ��Ч���ݸ���
	size_t capicity;  // �����ռ�Ĵ�С
}SeqList;

// ������ɾ���  �ӿ�
void SeqListInit(SeqList* psl, size_t capacity)		// ˳����ʼ��
{
	assert(psl != NULL);
	psl->array = (SLDataType*)malloc(sizeof(SLDataType)*capacity);
	psl->capicity = 0;
	psl->size = 0;
}
void SeqListDestory(SeqList* psl)	// ˳�������
{
	assert(psl != NULL);
	assert(psl->array != NULL);
	free(psl->array);	//�ͷſռ�
	psl->size = 0;
	psl->capicity = psl->size = 0;
}

void SeqListPrint(SeqList* psl)// ˳����ӡ
{
	assert(psl);
	for (size_t i = 0; i < psl->array; i++)
	{
		printf("%d", psl->array[i]);
	}
	printf("\n");
}
void CheckCapacity(SeqList* psl)//���ռ䣬������ˣ���������
{
	if (psl->array == psl->capicity)
	{
		size_t newcapicity = psl->capicity == 0 ? 4 : psl->capicity * 2;
		psl->array = (SLDataType*)relloc(psl->array, newcapicity * sizeof(SLDataType));
		psl->capicity = newcapicity;
	}
}
void SeqListPushBack(SeqList* psl, SLDataType x)// ˳���β��
{
	assert(psl);
	CheckCapacity(psl);
	psl->array[psl->size] = x;
	psl->size++;
}
void SeqListPopBack(SeqList* psl)// ˳���βɾ
{
	assert(psl);
	psl->array[psl->size - 1] = 0;
	psl->size--;
}
void SeqListPushFront(SeqList* psl, SLDataType x)// ˳���ͷ��
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
void SeqListPopFront(SeqList* psl)// ˳���ͷɾ
{
	assert(psl);
	for (size_t i = 0; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}
int SeqListFind(SeqList* psl, SLDataType x)// ˳������
{
	assert(psl);
	for (size_t i = 0; i < psl->size; i++)
	{
		if (psl->array[i] == x)
		{
			return i;	//���ؽǱ�
		}
	}
	return -1;
}
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)// ˳�����posλ�ò���x
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
void SeqListErase(SeqList* psl, size_t pos)// ˳���ɾ��posλ�õ�ֵ
{
	assert(pos >= 0 && pos < psl->size);
	for (size_t i = pos; i < psl->size - 1; i++)
	{
		psl->array[i] = psl->array[i + 1];
	}
	psl->size--;
}