#include<stdio.h>
int aworry1(double Air[8096][8096]);
int aworry2(double Air[8096][8096]);
int main()
{
	double A[8096][8096];
	aworry2(A);
	return 0;
} 
int aworry1(double Air[8096][8096])
{
	for(int i=0;i<8096;i++)
	{
		for(int j=0;j<8096;j++)
		{
			printf("%d/n",Air[i][j]);
		}
	}
	printf("put 1 !");
	return 0;
}
int aworry2(double Air[8096][8096])
{
	
		for(int j=0;j<8096;j++)
	{
	for(int i=0;i<8096;i++)
		{
			printf("%d/n",Air[i][j]);
		}
	}
	printf("put 2 !");
	return 0;
}
