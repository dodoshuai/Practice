#include<iostream>

using namespace std;




class A

{

public:

static A* getA(int x)

{




cout << "A() " << endl;

return new A(x);

//这里用new，而直接调用是因为静态方法只能访问类的静态成员，不能访问类的非静态成员;

//A* pa = (A*)malloc(sizeof(A));

//pa->A::A⑶；

//return pa;

}

static void deleteA(A* p)

{

cout << "A() _a = " << endl;

delete p;

}

void fun()

{

cout << _a << endl;

}

private:

A(int x)

:_a(x)

{

}

~A()

{

}

int _a;

};

class B : public A

{

public:

B()

:_b(1)

{

cout << "B()" << endl;

}

private:

int _b;

};




int main()

{

A* pa = A::getA(10);

//pa->deleteA(pa);

pa->fun();

B bb;

return 0;

}

