#include<iostream>
using namespace std;
int main()
{
	float r[6]={0.1,0.075,0.05,0.03,0.015,0.01};
	float p,m=0;
	cin>>p;
	if(p<=100000)
	m=p*r[0]+m;
	else
	{
	m=100000*r[0]+m;
	if(p<=200000)
	m=p*r[1]+m;
	else
	{
		m=m+100000*r[1];
		if(p<=400000)
		m=p*r[2]+m;
		else
		{
			m=m+200000*r[2];
			if(p<=600000)
			m=p*r[3]+m;
			else
			{
				m=m+200000*r[3];
				if(p<=1000000)
				m=p*r[4]+m;
				else
				{
					m=m+400000*r[4];
					if(p>1000000)
					m=(p-1000000)*r[5]+m;
				}
			}
		}
	}	
	}
	cout<<m<<endl;
	return 0;
}
