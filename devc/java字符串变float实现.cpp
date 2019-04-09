#include<iostream>
using namespace std;
#include<math.h>
#include<string>
float string_int(char *s);
int main()
{
	char a[100];
	cin>>a;
	cout<<string_int(a)<<endl;
	return 0;
}
float string_int(char *s)
{
	float z=0;
	//float x=0;
	int i=0;
	int j=0;
	for(;s[i]!='\0';i++)
	{
		if(s[i]=='.')
		{
			j=i;
			continue;
		}
		if(j==0)
		{
			z=z*10+(s[i]-'0');
		}
		if(j!=0&&i>j)
		{
			z=z+(s[i]-'0')*pow(10,j-i);	
		}
	}
	return z;
}
