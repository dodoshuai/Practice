#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int N;
	int i,j;
	int x;
	cin>>N;
	for(i=6;i<=N;i++)
	{x=1;
		for(j=2;j<=sqrt(i);j++)
		{
			if(i%j==0)
			x=x+i/j+j;
		}
		if(x==i)
		{
			cout<<i<<" its factors are ";
			for(j=i;j>1;j--)
			{
				if(i%j==0)
				cout<<i/j<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}
