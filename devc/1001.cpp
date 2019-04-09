#include<iostream>
using namespace std;
const  int N=20;
int main()
{
	int *p,i;
	p=(int *)new int[20];
	*p=1;
	*(p+1)=1;
	for(i=2;i<N;i++)
	{
		*(p+i)=*(p+i-1)+*(p+i-2);
	}
	for(i=0;i<N;i++)
	{
		cout<<*(p+i)<<endl;//printf("%d\n",*(p+i));
	}
	return 0;
}
