#include<iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	int a = A>B?A:B, b =A>B?B:A;
	while (b != 0) {
		int x = a % b;
		a = b;
		b = x;
	}
	int min = A * B / a;
	cout << min << endl;
	return 0;
}