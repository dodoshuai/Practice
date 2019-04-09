#include<iostream>
using namespace std;
int main()
{
	int a[]={1,2,3},b[]; 
		int c=5,d;
		b=a;
		d=c;
		cout<<a[0]<<a[1]<<a[2]<<endl;
		cout<<b[0]<<b[1]<<b[2]<<endl;
		cout<<"c="<<c<<" d="<<d<<endl;
	return 0;
}
