#include<stdio.h>
#include<math.h> 
int main()
{
	int num;
	for(num=100;num<200;num++)
	{
	
	for(int i=2;i<=sqrt(num);i++)
	{
		if(num%i==0)
		break;
		if(i==(int)sqrt(num))
		printf(" %d \n",num);
	}
		
	}
	return 0;
} 
