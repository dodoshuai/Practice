/*#include<stdio.h>
int main()
{
	int i;
	 float x=0,y=0;
	float M,m;
	int N;
	scanf("%f%d",&M,&N);
	m=M;
	for(x=0,y=M,i=1;i<=N;i++)
	{
		
		x=x+2*y;
		y=y/2;
	}
	
	x=x-m;
	printf("%.2f %.2f",y,x);
	return 0;
}*/

#include<stdio.h>
int main()
{
	
		float m =0;
		float n = 0;
		float sum = 0;
		scanf("%f",&m);
		scanf("%f",&n);
		for (int i = 1; i <= n; i++) {
			sum += m;
			m /= 2;
		}
		sum = sum * 2 - 1000;
		printf("%.2f ",m);
		printf("%.2f",sum);
}

/*#include <iostream>
#include <iomanip>
 
using namespace std;
 
int main()
{
    int i,t;
    float m,n,sum=0;
    cin>>m>>n;
    t=m;
    for(i=1;i<=n;i++)
    {
        sum=sum+2*m;
        m=m/2;
    }
    sum=sum-t;
    cout<<setiosflags(ios::fixed)<<setprecision(2);
    cout<<m<<" "<<sum<<endl;
    return 0;
}*/
