#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	int x=0,y=2;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		
		x=x+y;
			y=y*10+2;
	}
	cout<<x<<endl;
	return 0;
}
