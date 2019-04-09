#include<stdio.h>
int main()
{

	
	for(int i=0;i<32;i++)
	{int num=i;
	int a[5]={0};
		for(int j=4;j>=0;j--)
		{
		if(num%2==1)
		a[j]=1;
		else a[j]=0;
		num=num/2;
		}
		for(int k=0;k<5;k++)
	printf("%d",a[k]);
	if(i!=31)
	printf("\n");			
	}	
	return 0;
}
