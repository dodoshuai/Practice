#include<stdio.h>
int main(){
	int num[10];
	for(int i=0;i<10;i++){
		num[i]=i;
		printf("%d\n",num[i]);
	}
	int max=0;
	
	for(int i=0;i<=9;i++){
		if(num[i]>max){
			max=num[i]; 			
		}
	}
	printf("max=%d\n",max);
	return 0;
}
