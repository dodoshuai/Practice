#include<stdio.h>
int main(){
	
	int a,b,a1,b1,c;
	printf("�����벻Ϊ�����������\n");
	scanf("%d%d",&a,&b);
	a1=a;
	b1=b;
	c=0;
	for(int i=0;;i++){
		c=a%b;
		a=b;
		b=c;
		if(b==0)
		break;
	}
	printf("%d��%d�����Լ���ǣ�%d\n",a1,b1,a);
	return 0;
} 
