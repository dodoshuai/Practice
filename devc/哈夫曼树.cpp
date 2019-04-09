#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct {
	unsigned int weight;
	unsigned int parent, lchild, rchild;
}HTNode, *HuffmanTree;

typedef char ** HuffmanCode;

void Select(HuffmanTree *HT, int i, int *s1, int *s2)
{
	int j;//循环变量
	int min1 = 0, min2 = 0;
	for (j = 1; j <= i; j++)
	{
		if ((*HT)[j].parent == 0 && min1 == 0)
		{
			min1 = j;
			continue;
		}
		if ((*HT)[j].parent == 0 && min1 != 0)
		{
			min2 = j;
			break;
		}
	}
	for (j = 1; j <= i; j++)
	{
		if ((*HT)[j].parent == 0)
		{
			if ((*HT)[min1].weight>(*HT)[j].weight)
				min1 = j;
		}
	}
	for (j = 1; j <= i; j++)
	{
		if ((*HT)[j].parent == 0 && j != min1)
		{
			if ((*HT)[min1].weight>(*HT)[j].weight)
				min2 = j;
		}
	}
	*s1 = min1;
	*s2 = min2;
}

void HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n)
{
	int m;//结点数目
	int i, c;//循环变量
	int s1;
	int s2;
	int f;
	int start;
	char * cd;
	HuffmanTree p;

	if (n <= 1) return;
	m = 2 * n - 1;
	(*HT) = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));

	for (p = (*HT), i = 1; i <= n; ++i, ++p, ++w)
	{
		p->weight = *w;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (; i <= m; ++i, ++p)
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	for (i = n + 1; i<m; ++i)
	{
		Select(&(*HT), i - 1, &s1, &s2);
		(*HT)[s1].parent = i;  (*HT)[s2].parent = i;
		(*HT)[i].lchild = s1; (*HT)[i].rchild = s2;
		(*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
	}
	(*HC) = (HuffmanCode)malloc((n + 1) * sizeof(char *));
	cd = (char *)malloc(n * sizeof(char));
	cd[n - 1] = '\0';
	for (i = 1; i <= n; ++i)
	{
		start = n - 1;
		for (c = i, f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)

			if ((*HT)[f].lchild == c) cd[--start] = '0';
			else cd[--start] = '1';
			(*HC)[i] = (char *)malloc((n - start) * sizeof(char));
			strcpy((*HC)[i], &cd[start]);

	}
	free(cd);
}

void printHuffmanTree(HuffmanTree HT,int N) {
	int M;
	M = 2 * N;
	printf("\n");
	printf("data, weight, parent, lchild, rchild\n");
	for (int i = 1; i <= M; i++) {
		if (i > N) {
			printf("  -, %5d, %5d, %5d, %5d\n", HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
		else {
			printf("   %5d, %5d, %5d, %5d\n",  HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
		}
	}
	printf("\n");
}

void printHuffmanCoding(HuffmanCode HC,int N) {
	printf("\n");
	for (int i = 1; i <= N; i++) {
		printf("%s\n", HC[i]);
	}
	printf("\n");
}

int main()
{
	HuffmanTree tree1;
	HuffmanCode code1;
	int w[8] = { 1,2,3,4,5,6,7,8 };
	int m = 8;
	HuffmanCoding(&tree1, &code1, w, m);
	printHuffmanTree(tree1, m);
	printHuffmanCoding(code1,m);
	getchar();
	return 0;
}
