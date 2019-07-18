#include<iostream>
#include<cmath>
using namespace std;

int divide(int dividend, int divisor) {
	long a = 0;
	int count = 1;
	int flag = 0;
	if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
		flag = 0;
	}
	else {
		flag = 1;
	}
	long x = abs((long)dividend);
	long y=abs((long)divisor);
	while (1) {
		//if (count < 1) {
			//break;
		//}
		x-=y;
		a += count;
		if (x> 0) {
			y <<= 1;
			count <<= 1;
		}
		else if (x < 0) {
			x+= y;
			a -= count;
			if (count == 1) {
				break;
			}
			y >>= 1;
			count >>= 1;
		}
		else {
			break;
		}
	}
	if (flag == 1) {
		a = 0 - a;
	}
	if (a > INT_MAX) {
		a = INT_MAX;
	}
	std::cout << a << std::endl;
	return a;
}
int main() {

	int a, b;
	while (cin >> a >> b) {
		divide(a, b);
	}
	return 0;
}