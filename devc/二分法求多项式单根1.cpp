#include<stdio.h>
#include<math.h>
double a3,a2,a1,a0;
int main(void)
{double fun(double n);
	
	double a,b;
	double x;
	double left,mid,right;
	scanf("%lf%lf%lf%lf",&a3,&a2,&a1,&a0);
	scanf("%lf%lf",&a,&b);
	left=a;
	right=b;
	while(left<right-0.001&&fun(left)*fun(right)<=0)
	{
		if(fun(left)==0)
		{
			printf("%.2f",left);
			return 0;
		}
		if(fun(right)==0)
		{
			printf("%.2f",right);
			return 0;
		}
		 mid = (left + right) / 2;  
        if (fun(mid) * fun(left) > 0)  
        {  
            left = mid;  
        }  
        else  
        {  
            right = mid;  
        }  
		
	}

		 printf("%.2f", mid);  
	return 0;
} 
double fun(double n)
{
	double NUM;
	NUM=a3*pow(n,3)+a2*pow(n,2)+a1*pow(n,1)+a0;
	return NUM;
}
