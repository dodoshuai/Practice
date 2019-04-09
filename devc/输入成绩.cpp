#include<iostream>
#include"scostu.h"
#include<vector>
using namespace std;
int main()
{
	
	/*Student stu1("李小明","990201",90,80,70);
	stu1.show();
	cout<<endl;
	Student stu2("张永生","990202",95,85,75);
	stu2.show();
	cout<<endl;
	stu2.show2();
	*/
	Student * A= new Student [100];
	char *x;
	char *n;
	float c,e,m;
	int j,i;
	i=0;	
	while(cin>>x>>n>>c>>e>>m)
	{
		if(cin.get()==EOF)
		break;
		A[i++](x,n,c,e,m);
	}
	
		A[i-1].show2();
	delete []A;
	return 0;
	
}
