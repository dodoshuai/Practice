#include<iostream>
using namespace std;
int main()
{
	int add(int a,int b);
	int a,b;
	cin>>a>>b;
	cout<<add(a,b);
  
  return 0;
}
/*int add(int a,int b)
{
	if(b==0)
	return a;
	int a1=a^b;
	int b1=(a&b)<<1;
	cout<<add(a1,b1)<<endl;
	return add(a1,b1);
}*/
int add(int a,int b)
{
	if(b==0)
	return a;
	int a1=a^b;
	//cout<<a1<<endl;
	int b1=(a&b)<<1;
	//cout<<b1<<endl;
//	return add(a1,b1);
return a1+b1;
}
