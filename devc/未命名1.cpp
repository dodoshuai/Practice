#include <iostream>
#include <math.h>
class complex
{ private:
    double real;
    double imag;
  public:
    void set_complex(double r,double i)
	{ real=r;imag=i;}
    double get_real( )
	{return real;}
    double get_imag( )
	{return imag;}
    double get_abs( )
	{ double t;
      t=sqrt(real*real+imag*imag);
      return t;
	}
};
int main()
{ complex A;
  A.set_complex(3.0,4.0);
  cout <<"real of complex A=";
  cout <<A.real()<<endl;
  cout <<"imag of complex A=";
  cout <<A.get_imag()<<endl;
  cout <<"abs of complex A= ";
  cout <<A.get_abs()<<endl;
}

