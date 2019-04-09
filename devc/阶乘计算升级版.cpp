#include <stdio.h>

void Print_Factorial ( const int N );

int main()
{
    int N;
				
    scanf("%d", &N);
    Print_Factorial(N);
    return 0;
}
void Print_Factorial(const int N)
{
	int x;
	x=N;
	int y=1;
	if(x>=0&&x<=12)
	{
		for(int i=1;i<=x;i++)
		{
			y*=i;	
		}
		if(x==0)
		{
			y=0;
		}
		printf("%d",y);
		
	}
	else if(x<0)
	{
		printf("Invalid input");
	}
	else if(x>12&&x<=1000)
	{int num[3000]={0};
		int k=1;
		int n=0;
		int a;	
		int b;
		int c;
		num[0]=1;
			for(int a=2;a<=x;a++)
			{
				for(int j=0;j<k;j++)
				{
					b=num[j]*a+n;
					num[j]=b%10;
					n=b/10;					
				}
				while(n!=0)
				{
					num[k]=n%10;
					k++;
					n=n/10;
				}
			}
		for(c=k-1;c>=0;c--)
		{
			printf("%d",num[c]);
		}
		printf("\n");
	}
}
