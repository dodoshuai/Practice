#include<iostream>
using namespace std;
int main()
{
	int n;
 int i;
 int temp;
 int s=0;
 int a[10];
 cin>>n;
 temp=n;
 for(;temp!=0;)
 {
 a[s++]=temp%10;
 temp/=10;
 }
 cout<<s<<endl;
 for(i=s-1;i>=0;i--)
 {
 	if(i!=s-1)
 	cout<<" ";
 	cout<<a[i];
 }
 cout<<endl;
 for(i=0;i<s;i++)
 {
 	cout <<a[i];
 }
	cout<<endl;
return 0;
} 
/*# include <stdio.h>
int main()
{
 int n;
 int i;
 int temp;
 int count=0;
 int a[10];
 printf("输入一个不多于5位的整数:\n");
 scanf("%d",&n);
 temp=n;
 while(temp!=0)
 {
 a[count++]=temp%10;
 temp/=10;
 }
 printf("%d\n",count);
 for(i=count-1;i>=0;i--)
 {
 	if(i!=count-1)
 	printf(" ");
 printf("%d",a[i]);
 }
 printf("\n");
 for(i=0;i<count;i++)
 {
 	printf("%d",a[i]);
 }
 printf("\n");
}*/
