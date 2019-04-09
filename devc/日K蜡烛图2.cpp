#include<stdio.h>
int main()
{
	float Open,High,Low,Close;
	scanf("%f%f%f%f",&Open,&High,&Low,&Close);
	if(Open>Close)
	{
		printf("BW-Solid");
		if(Low<Close&&Open<High)
		{
			printf(" with Lower Shadow and Upper Shadow");
		}
		else if(Low<Close)
		{
			printf(" with Lower Shadow");
		}
		else if(High>Open)
		{
			printf(" with Upper Shadow");
		}
	}
	else if(Open<Close)
	{
		printf("R-Hollow");
		if(Low<Open&&Close<High)
		{
			printf(" with Lower Shadow and Upper Shadow");
		}
		else if(Low<Open)
		{
			printf(" with Lower Shadow");
		}
		else if(High>Close)
		{
			printf(" with Upper Shadow");
		}	
	}
	else if(Open==Close)
	{
		printf("R-Cross");
		if(Low<Open&&Close<High)
		{
			printf(" with Lower Shadow and Upper Shadow");
		}
		else if(Low<Open)
		{
			printf(" with Lower Shadow");
		}
		else if(High>Close)
		{
			printf(" with Upper Shadow");
		}
	}
	
	return 0;
}
