#include<stdio.h>
int main()
{
	int N,U,D;
	int j;
	scanf("%d%d%d",&N,&U,&D);
	for(int i=0;i<N;i-=D,j+=2)
	{
		i+=U;
			
	} 
	printf("%d\n",j-1);
	return 0;
}
