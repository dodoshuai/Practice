#include<stdio.h>
int main()
{
	int n_time;
	int l_time;
	int f_time;
	int le,ri,num_1,num_2;
	scanf("%d%d",&n_time,&l_time);
	le=n_time/100;
	ri=n_time-le*100;
	num_1=l_time/60;
	num_2=l_time%60;
	if(num_2+ri>=60)
	{
	ri=num_2+ri-60;
	le+=1;
	}
	else if (num_2+ri<0)
	{
		ri=60+num_2+ri;
		le-=1;
	} 
	else
	{
	
		ri=num_2+ri;
	}
	f_time=(le+num_1)*100+ri;
	printf("%d",f_time);
	return 0;
}
