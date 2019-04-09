#include<stdio.h>
int main(){
	int year =1000;
	for(;year<=2000;year++){
		if(year%4==0){
			if(year%100==0){
				if(year%400==0){
					printf("%d是闰年\n",year);
				}			
			}
			else{
				printf("%d是闰年\n",year);
			}
		}		
	}
	return 0;
}
