#include<iostream>

using namespace std;

int main() {
	int n;
	long long a[22];
	a[2] = 1;
	a[3] = 2;
	for (int i = 4; i < 22; i++) {
		a[i] = (i - 1) * (a[i - 2] + a[i - 1]);
	}
	while (cin >> n) {
		
		cout << a[n] << endl;
	}
	
	return 0;
}