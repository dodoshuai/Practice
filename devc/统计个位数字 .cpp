#include <stdio.h>

int Count_Digit ( const int N, const int D );

int main()
{
    int N, D;
				
    scanf("%d %d", &N, &D);
    printf("%d\n", Count_Digit(N, D));
    return 0;
}
int Count_Digit(const int N,const int D)
{
	int x;
	int y;
	int i;
	int z=0;
	x=N;
	y=D;
	while(1)
	{
		i=x%10;
		if(i==y||i==(-y))
		{
			z++;
		}
		x=x/10;
		if(x==0)
		break;	
	}	
	return z;
}
