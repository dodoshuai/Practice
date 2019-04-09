#include<stdio.h>
	int A[50];
	char s[100][100];
int main()
{
	int fun(int n);

	for(int i=0;i<50;i++)
		A[i]=i+1;
	for(int j=0;j<100;j++)
		{
			for(int k=0;k<100;k++)
			{
				s[j][k]=0;
			}
		}
	int x;
	scanf("%d",&x);
	
	for(int i=0;i<x-1;i++)
	{
		if(s[i][i+1]==0)
		{
			s[i][i+1]=1;
		}
		else	if(s[i][i+1]){
		
		}
		
		for(int j=0;j<100;j++)
		{
			for(int k=0;k<100;k++)
			{
				s[j][k]=0;
			}
		}
	}
	return 0;
}
int fun(int n)
{

	for()
	return 0;
}
