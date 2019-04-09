#include<iostream>
using namespace std;
class book{
	private:
		int qu[5];
		int price[5];
	public:
		book()
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
			for(i=0;i<5;i++)
			{
				z=qu[i]*price[i];
				cout<<z<<endl;
			}
		}
};
