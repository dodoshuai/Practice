
/*#include<stdio.h>
int main()
{
	int i,x,y,m,n,p;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m > n){
			p = m;
			m = n;
			n = p;
		}
		x=y=0;
		for(i = m; i <= n; i++)
			if(i%2 ==0)
				x+=i*i;
			else
				y+=i*i*i;
		printf("%d %d\n",x,y);
	}
}*/

#include<stdio.h>
int main()
{
	int a[1005]={0};
	int b[1005]={0};
	int i,j;
	int n;
	int m,x=0,y=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		b[i]=a[n-m+i];
	}
	for(j=n-1;j-m>=0;j--)
	{
	
		a[j]=a[j-m];
		
	}
	for(i=0;i<m;i++)
	{
		a[i]=b[i];
		 }
	for(i=0;i<n;i++)
	{
		if(i!=0)
		printf(" ");
	printf("%d",a[i]);
	}
	return 0;
}

