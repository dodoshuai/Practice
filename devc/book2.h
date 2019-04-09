#include<iostream>
using namespace std;
class book2{
	private:
		int qu[5];
		int price[5];
	public:
		book2()
		{
			int i;
			for(i=0;i<5;i++)
			{
			qu[i]=i+1;
			price[i]=(i+1)*10;
			}
		}
		void print()
		{
			int i,z;
			int *p1;
			p1=qu;
			int *p2;
			p2=price;
		
			for(i=0;i<5;i++)
			{			
				cout<<(*(p1+i))*(*(p2+i))<<endl;
			}
		}
};
