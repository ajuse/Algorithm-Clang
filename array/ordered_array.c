#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct stAry{
	int arySize;
	int *pAry;
	int aryUsed;
}stAry;


int del_ary(stAry *stArray, unsigned int idx)
{
	if (stArray == NULL || idx > stArray->aryUsed)
		return -1;

	memcpy(&stArray->pAry[idx], &stArray->pAry[idx + 1], (stArray->aryUsed - idx - 1) * sizeof(int));
	stArray->aryUsed -= 1;

	return 0;
}

int add_ordered_ary(stAry *stArray, int elm)
{
	int i = 0;

	if (stArray == NULL || stArray->aryUsed >= stArray->arySize)
		return -1;

	// find index of elm
	for (i = 0; i < stArray->aryUsed; i++)
		if (stArray->pAry[i] > elm)
			break;

	if (i < stArray->aryUsed)
		memmove(&stArray->pAry[i + 1], &stArray->pAry[i], (stArray->aryUsed - i) * sizeof(int));

	stArray->pAry[i] = elm;
	stArray->aryUsed += 1;

	return 0;
}

int main()
{
	int testAry[] = {1,2,3,4,5,6,7,8,9,8,7,6,5,5,4,3,2,2,1,6,7,85,3,2};
	int i = 0;
	int testAryLen = sizeof(testAry) / sizeof(int);
	stAry stArray = {40, NULL, 0};

	stArray.pAry = (int *)malloc(stArray.arySize * sizeof(int));

	if (stArray.pAry == NULL)
		return -1;

	memset(stArray.pAry, 0, stArray.arySize * sizeof(int));

	for (i = 0; i < testAryLen; i++)
		if (0 != add_ordered_ary(&stArray, testAry[i]))
			return -1;

	for (i = 0; i < stArray.aryUsed; i++)
		printf("%d ", stArray.pAry[i]);

	printf("\n");

	printf("arySize = %d, aryUsed = %d\n", stArray.arySize, stArray.aryUsed);

	del_ary(&stArray, 4);

	for (i = 0; i < stArray.aryUsed; i++)
		printf("%d ", stArray.pAry[i]);

	printf("\n");

	printf("arySize = %d, aryUsed = %d\n", stArray.arySize, stArray.aryUsed);

	return 0;
}
	
