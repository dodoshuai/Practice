#include<stdio.h>
int main(){
	int a,b;
	a=10;
	b=5;
	if(a>b){
		a^=b;
		b^=a;
		a^=b;
	}
	printf("a=%d\nb=%d\n",a,b);
	return 0;
}
