#include<stdio.h>
int main()
{
	int N,M;
	int a[105][105];
	int b[105][105]={0};
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	for(int i=0;i<N;i++){  
        for(int j=0;j<N;j++){  
            b[i][j]=a[i][j];  
        }  
    }  
    if(M==0)
	{ 
        for(int i=0;i<N;i++){  
            for(int j=0;j<N;j++){  
                if(i==j) b[i][j]=1;  
            }  	
	}
	}
	if(M==1)
	{
	
	}
	else 
			for(int k=1;k<M;k++)
	{
	
	
	for(int i=0;i<N;i++)
	{
		
		for(int j=0;j<N;j++)
		{
			int x=0;
		for(int l=0;l<N;l++)
		{
			x=x+b[i][k]*a[k][j];
		}
		b[i][j]=x;	
		}
	}
	}	
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			printf("%d ",b[i][j]);
		}
		printf("\n");
	}
	
	return 0;
} 
