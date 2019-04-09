#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int i=100;
	int a,b,c;
	for(;i<1000;i++)
	{
		a=i%10;
		b=(i/10)%10;
		c=(i/100);
		if(i==pow(a,3)+pow(b,3)+pow(c,3))
		cout<<i<<endl;
	}
	return 0;
}
