#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int i;
	float x=0,y=0,z=0;
	for(i=1;i<=a;i++)
	{
		x=x+i;
		
	}
	for(i=1;i<=b;i++)
	{
		y=y+(i*i);
	
	}
	for(i=1;i<=c;i++)
	{
		z+=1.0/i;
	
	}

	cout<<setiosflags(ios::fixed)<<setprecision(2)<<x+y+z<<endl;
	return 0;
}
