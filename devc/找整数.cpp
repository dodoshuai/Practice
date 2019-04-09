#include<stdio.h>
int main()
{
	int N;
	int a[1005];
	int M;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
	scanf("%d",&M);
	for(int j=0;j<N;j++)
	{
		if(M==a[j])
		{
		printf("%d",j+1);
		break;
		}
	}
return 0;
}
