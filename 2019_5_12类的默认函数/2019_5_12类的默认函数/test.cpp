
#include"date.h"

int main() {
	//Date a(1000, 1, 1);
	Date b(1998, 5, 12);
	b.Print();
	//b += 1000;
	//b.Print();
	//b = b + 1000;
	//b.Print();
	Date c(2019, 5, 12);
	c.Print();
	b = c++;
	b.Print();
	b = ++c;
	b.Print();
	getchar();
	return 0;
}