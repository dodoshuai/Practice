#include<stdio.h>
int main()
{
int P(int a);
/*		int l,m,n;
	int num;
	scanf("%d",&num);
	l=num/100;
	m=num/10-l*10;
	n=num-100*l-10*m;
	printf("%d",n*100+m*10+l);*/
	P(45878);
	return 0;
}
int P(int a){



		
	
	//	printf("%d\n",a);
	if(a>0)
	{
		printf("%d\n",a%10);
			P(a/10);	
}
	//printf("%d\n",z);
	return 0;
} 
/*
#include<stdio.h>
void rev(int n){
   if(n > 0) {            //�жϸ����Ƿ����0
       printf("%d", n%10); //���ĩλ��ֵ
       rev(n/10);        //�ݹ��������10���ʣ��ֵ
   }
}
int main(){
   rev(7854);        //��������1234
   return 0;
}*/
