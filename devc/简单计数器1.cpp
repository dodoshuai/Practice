#include<stdio.h>
int main()
{
	int A,B,C;
	char Y;
	scanf("%d %c%d",&A,&Y,&B);
	if(Y=='+')
	{
		C=A+B;
		printf("%d",C);	
	}
	else
	if(Y=='-')
	{
		C=A-B;
		printf("%d",C);
	}
	else
	if(Y=='*')
	{
		C=A*B;
		printf("%d",C);
	}
	else
	if(Y=='/')
	{
		C=A/B;
		printf("%d",C);
	}
	else if(Y=='%')
	{
		C=A%B;
		printf("%d",C);
	}
	else
	{
		printf("ERROR");
	}

	return 0;
} 
