/*#include<stdio.h>

int main(){
	 
	const float c=1.2;
	const float k=4.3;
	const float j=6.4;
	printf("volume=%.3f\n",c*k*j);
}
*/ 
/*#include  <stdio.h>
int main()
{
    int    a = 2, b = 3 ;
    float  x = 3.5, y = 2.5 ;
    printf("%f,%d", (float)(a+b) / 2 + (int)x % (int)y,(int)x % (int)y) ;
    return 0;
    
    int a=3;
    printf("%d\n",a+=a-=a*a);
    
    

}
*/
#include <stdio.h>
int main()
{ 
   int a=1,b=2,m=0,n=0,k;
   k=(n=b>a)||(m=a<b);
   printf("%d,%d\n",k,m);
   if(!0)
   printf("!1\n!1\n");
   else
   printf("!0\n!0\n");
   return 0;
}







node *he(node *p,node *q)
{
	node *p1,*p2,*p3,*p4,*p5;
	p3=(node*)malloc(sizeof(node));
	p3->a=0;
	p3->exp=0;
	p3->next=NULL;
	p4=p3;
	p1=p;
	p2=q;
	while( p1!=NULL && p2!=NULL)
	{
		if( p1->exp < p2->exp)
		{
			p3->next=p1;
			p3=p1;
			p1=p1->next;
		}
		else if(p1->exp > p2->exp)
		{
			p3->next=p2;
			p3=p2;
			p2=p2->next;
		}
		else if(p1->exp==p2->exp)
			{
				if((p1->a=(p1->a+p2->a))!=0)
				{
					p3->next=p1;
					p3=p1;
					p1=p1->next;					
				}
				else
				{
					p5=p1;
					p1=p1->next;
					free(p5);
				}
				p5=p2;
				p2=p2->next;
				free(p5);
			}
	}
		if(p1!=NULL)
			p3->next=p1;
		else
			p3->next=p2;
			
		return p4;
 }//合成
 typedef struct node{
    	int a;
	    int exp;
		node *next;
};//结构体

