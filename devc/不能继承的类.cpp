#include<iostream>

using namespace std;




class A

{

public:

static A* getA(int x)

{




cout << "A() " << endl;

return new A(x);

//������new����ֱ�ӵ�������Ϊ��̬����ֻ�ܷ�����ľ�̬��Ա�����ܷ�����ķǾ�̬��Ա;

//A* pa = (A*)malloc(sizeof(A));

//pa->A::A�ǣ�

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

