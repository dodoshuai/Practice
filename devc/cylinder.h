#include<iostream>
using namespace std; 
class cylinder{
	private:
		double rab;
		double high;
		double volu;
	public:
		cylinder(double x,double y)
		{
			rab=x;
			high=y;
			volu=r*r*3.14;
		}
		void vol()
		{
			cout<<volu<<endl;
		}		
};
