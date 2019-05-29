#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int x=a;
	int y=b;
	while (x != 0 && y != 0) {
		int x1 = x ^ y;
		int y1 = x & y;
		y = y1 << 1;
		x = x1;
	}
	/*int x1 = x ^ y;
	int y1 = x & y;
	y = y1 << 1;
	x = x1;
	*/
	int num = x ^ y;
	cout << num << endl;
	return 0;
}