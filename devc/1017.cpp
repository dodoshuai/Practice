#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	float x=1,y=2;
	int i,j;
	int N;
	float m=0;
	
	cin>>N;
	for(i=1;i<=N;i++)
	{
	m=m+y/x;
	j=y;
	y=x+y;
	x=j;	
	}
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<m<<endl;
	return 0;
}
