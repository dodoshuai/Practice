#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
//int main(){
	
	/*char dog[]="wang\0miao";
	//printf("%d\n",sizeof(dog));
	cout<<sizeof(dog)<<endl;
	cout<< strlen(dog)<<endl;
	*/
/*	char ccString1[]="Is Page Fault??";
	char ccString2[]="No Page Fault??";
	strcpy(ccString1,"No");
	if(strcmp(ccString1,ccString2)==0)
	cout<<ccString2<<endl;
	else
	cout<<ccString1<<endl;
	
	cout<<"c1="<<sizeof(ccString1)<<endl;
	cout<<"c2="<<sizeof(ccString2)<<endl; 
	*/
/*	class A {
public:
int GetValue() //const 
{
vv = 1;
return vv;
}
private:
//mutable int vv;	
int vv;
};
	A b;
	return 0;
}

*/

class Base {
public:
Base(int j): i(j) {}
virtual~Base() {}
void func1() {
i *= 10;
func2();
}
int getValue() {
return i;
}
protected:
virtual void func2() {
	
	cout<<"Base-func2!"<<endl;
i++;
}
protected:
int i;
};
class Child: public Base {
public:
Child(int j): Base(j) {}
void func1() {
i *= 100;
func2();
}
protected:
void func2() {
	cout<<"Child-func2!"<<endl;
i += 2;
}
};
int main() {
	Base * pb = new Child(1);
pb->func1();
cout << pb->getValue() << endl; delete pb; }

