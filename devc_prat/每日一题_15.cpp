//#include <iostream>
//#include<stdio.h>
//using namespace std;
/*int main(void)
{
const int a = 10;
int b=20;
int * p = (int *)(&a);
//int * p = &a;
printf("%d----%d----%d\n",&a,p,&b);
cout<<"a = "<<a<<", *p = "<<*p<<endl;
*p = 20;
printf("%d----%d\n",&a,p);
cout<<"a = "<<a<<", *p = "<<*p<<endl;
return 0;
}*/
/*int a=0;
class Widget{
	public: 
	Widget(){
	}
		Widget(Widget &q){
			a++;
		}
};

Widget f(Widget u)
{
Widget v(u);
Widget w=v;
return w;
}
int main(){
Widget x;
Widget y=f(f(x));
cout<<a<<endl;
return 0;
} 
*/
#include<iostream>
using namespace std;
class Base
{
public:
virtual int foo(int x)
{
	cout<<"1:"<<x*10<<endl;
return x * 10;
}
int foo(char x[14])
{
	cout<<"2:"<<sizeof(x)<<endl;//指针大小为4个字节---此处的大小位指针大小而不是数组大小 
return sizeof(x) + 10;
}
};
class Derived: public Base
{
int foo(int x)
{
	cout<<"3:"<<x*20<<endl;
return x * 20;
}
virtual int foo(char x[10])
{
		cout<<"4:"<<sizeof(x)+20<<endl;
return sizeof(x) + 20;
}
} ;
int main()
{
Derived stDerived;
Base *pstBase = &stDerived;
char x[17];
printf("%d\n", pstBase->foo(100) + pstBase->foo(x));
return 0;
} 

