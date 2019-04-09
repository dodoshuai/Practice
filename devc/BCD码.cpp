#include<stdio.h>
#include<math.h>
int main()
{
	int N,K,L,sum;
	int i,s[8];
	K=0;
	L=0;
	scanf("%d",&N);
	for(i=0;i<8;i++)
	{
		if(N<pow(2,(8-i-1)))
		{
			s[i]=0;
		//	printf("%d %d 0\n",pow(2,(8-i-1)),N);
		}
		else if(N>=pow(2,(8-i-1)))
		{
			s[i]=1;
			N=N-pow(2,(8-i-1));
			//printf("%d %d 1\n",pow(2,(8-i-1)),N);
		}
	}

	for(i=0;i<4;i++)
	{
		if(s[i]==1)
		K+=pow(2,(4-i-1));
	}
	for(i=4;i<8;i++)
	{
		if(s[i]==1)
		L+=pow(2,(8-i-1));
	}
//	printf("%d %d\n",K,L);
	sum=K*10+L;
	printf("%d",sum);
	return 0;
} 
