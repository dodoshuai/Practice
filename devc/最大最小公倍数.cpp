#include<stdio.h>

	int main()  
{  
    int n,a;  
    scanf("%d",&n);  
    if(n<3)  
        a=n;  
    else{  
    if(n%2!=0)  
        a=n*(n-1)*(n-2);  
    else if(n%3!=0)  
        a=n*(n-1)*(n-3);  
    else  
        a=(n-1)*(n-2)*(n-3);  
    }  
     printf("%d",a); 
    return  0;  
}  

