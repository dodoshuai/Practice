#include<stdio.h>
int main()
{
	int s1,f1;
	int s2,f2;
	scanf("%d:%d",&s1,&f1);
	if(s1>=12&&s1<24)
	{	f2=f1;
	if(s1>=13)
		s2=s1-12;
		else
		s2=s1;
	
		printf("%d:%d %s",s2,f2,"PM");
	}
	else
	{	f2=f1;
		if(s1==24)
		s2=s1-24;
		else
		{
	
		s2=s1;
		
		}
			printf("%d:%d %s",s2,f2,"AM");
	}
	
	return 0;
}

