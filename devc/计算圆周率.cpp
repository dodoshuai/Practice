#include<stdio.h>
int main()
{
  double n,m;
  double x;
  double y;
  int i;
  n=1;
  m=1;
  y=1;
  scanf("%lf",&x);
  for(i=1;(n/m)>=x;i++)
  {
    
    n*=i;
    m*=((2*i)+1);
   y+=(n/m);
  }
  y*=2;
  printf("%.6lf",y);
  return 0;
}
  
