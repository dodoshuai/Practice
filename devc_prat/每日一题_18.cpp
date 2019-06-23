#include <iostream>
using namespace std;
class A{
public:
void print()
{
cout << "A:print()";
}
};
class B: private A
{
public:
void print()
{
cout << "B:print()";
}
};
class C: public B
{
public:
void print()
{
A:: print();
}
};
int main()
{
C b;
b.print();
}
