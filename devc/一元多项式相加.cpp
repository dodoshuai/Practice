#include<stdio.h>
#include<stdlib.h>
typedef int Status;

typedef struct{
	float coef;
	int expn;
}term,ElemType; 
 
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}*Link,*LinkList;

typedef LinkList polynomail;

Status cmp(term a,term b)
{
	if(a.expn>b.expn)
	{
		return 1;
	}
	if(a.expn==b.expn)
	{
		return 0;
	}
	if(a.expn<b.expn)
		return -1;
}

void CreatPolyn(polynomail *L,int m)
{
	polynomail p1,p2;
	int i;
	(*L)=(polynomail)malloc(sizeof(LNode));
	p1=*L;
	//scanf("%f%d",&p1->data.coef,&p1->data.expn);
	p1->next=NULL;
	p2=p1;
	p1=p1->next;
	
	for(i=0;i<m;i++)
	{
		
		p1=(polynomail)malloc(sizeof(LNode));
		scanf("%f%d",&p1->data.coef,&p1->data.expn);
		p2->next=p1;
		p1->next=NULL;
		p2=p1;		
	}
	
}

void printPolyn(polynomail P)
{
	LinkList q = P->next;  
    printf("打印多项式的线性表：[");  
    while(q){  
        printf("(%.2f,%d)  ",q->data.coef, q->data.expn);  
        q = q->next;  
    }  
    printf("]\n\n");  
}

void AddPolyn(polynomail *Pa,polynomail *Pb)
{
	polynomail ha,hb,qa,qb,s1,s2;
	float sumOfCoef;  
	term a,b;
	ha=*Pa;
	hb=*Pb;
	qa=*Pa;
	qb=*Pb;
	while(qa&&qb)
	{
		a=qa->data;
		b=qb->data;
		switch(cmp(a,b))
		{
			case -1:{ha->next=qa; ha=qa; qa=qa->next;
				break;
			}
			case 0:{sumOfCoef = qa->data.coef + qb->data.coef;
				if(sumOfCoef!=0.0)
				{
					s1=qb;
					qa->data.coef = sumOfCoef;                       
                    ha->next = qa;  
                    ha = qa;  
                    qa = qa->next;  
                    qb = qb->next; 
				 	free(s1);
				}
				else {
					s1=qa;
					s2=qb;
					ha=qa->next;
					qa=qa->next;
					qb=qb->next;
					free(s1);  
                    free(s2); 
				}
			
				break;
			}
			case 1:{ha->next=qb;ha=qb;qb=qb->next;
				break;
			}
		}
	}
	ha->next = qa?qa:qb;//插入剩余段  
    free(Pb);
}

int main()
{
	/*int sum;
	polynomail red;
	scanf("%d",&sum);
	CreatPolyn(&red,sum);
	printPolyn(red);
	return 0;
	*/
	polynomial Pa;  
    createPolyn(&Pa, 4);//初始化并创建多项式链表Pa  
    printPolynomial(Pa);  
  
    polynomial Pb;  
    createPolyn(&Pb, 3);//初始化并创建多项式链表Pa  
    printPolynomial(Pb);  
  
    printf("执行多项式相加以后\n");  
    addPolyn(&Pa, &Pb);  
    printPolynomial(Pa);  
}
