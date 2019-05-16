#include<stdio.h>

int main(){
union student{
	int i;				//00000001   high --- low
	unsigned char ch;	//01
}a;
a.i=1;
printf("%x\n",a.ch);
return 0; 	
}
