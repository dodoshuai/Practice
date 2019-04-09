#include<stdio.h>
int main()
{
	int N;
	int count=0;
	int sum=0;
	scanf("%d",&N);
	for(int i=N;i<(N+4);i++)
	{
		for(int j=N;j<(N+4);j++)
		{
			for(int k=N;k<(N+4);k++)
			{	
				if(i!=j&&j!=k&&i!=k)
				{ 
					sum=i*100+j*10+k;
					printf(" %d",sum);
					count++;
					if(count%6!=0)
				printf(" ");
				
				else if(count%6==0)
				printf("\n");
				} 
				
				 
			}
		}
	}
	return 0;
}
