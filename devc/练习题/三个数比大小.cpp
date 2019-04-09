#include<stdio.h>
int main(){
	int a,b,c;
	a=5;
	b=2;
	c=7;
	if(a>b){
		a^=b;
		b^=a;
		a^=b;
	}
	if(a>c){
		a^=c;
		c^=a;
		a^=c;
	}
	if(b>c){
		b^=c;
		c^=b;
		b^=c;
	}
	printf("%d %d %d\n",c,b,a);
	return 0;
}
