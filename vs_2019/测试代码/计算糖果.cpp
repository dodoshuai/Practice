#include<iostream>

using namespace std;

int main() {
	int a[4];
	for (int i = 0; i < 4; i++) {
		cin >> a[i];
	}
	int d = (a[0] + a[2]) / 2;
	int b = (a[1] + a[3]) / 2;
	int c = a[3] - b;
	if(d>=0&&b>=0&&c>=0)
	cout << d << " " << b << " " << c << endl;
	else {
		cout << "NO" << endl;
	}
	return 0;
}