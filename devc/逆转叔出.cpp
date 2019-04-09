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
   if(n > 0) {            //判断该数是否大于0
       printf("%d", n%10); //输出末位数值
       rev(n/10);        //递归迭代整除10后的剩余值
   }
}
int main(){
   rev(7854);        //样例输入1234
   return 0;
}*/
