#include<stdio.h>
double  l_e(double a1);
int main()
{
 double a;
 int  foot;
 int inch;
  scanf("%lf",&a);
  foot=(int)l_e(a);
  inch=(int)((l_e(a)-foot)*12);
  printf("%d %d",foot,inch);
  return 0;
  
}
double  l_e(double a1)
{
  return a1/30.48;
}
