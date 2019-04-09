#include<stdio.h>
int main()
{
  int N,M;
  int j=0;
  int sum=0;
  scanf("%d%d",&N,&M);
  for(int i=N;i<=M;i++)
  {
   
    printf("%5d",i);
    sum+=i; 
	j++;
	if(j%5==0)
    {printf("\n");
 
    }
  }
  printf("\n");
  printf("Sum = %d\n",sum);
  return 0;
}
