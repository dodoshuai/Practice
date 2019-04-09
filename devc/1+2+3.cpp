#include<stdio.h>
int N;
int main()
{
	int add(int a);
	int x=0;
	scanf("%d",&N);
	x=add(N);
	printf("%d\n",x);
	return 0;
}
int add(int a)
{	
	return a>0?a+add(a-1):0;
}
