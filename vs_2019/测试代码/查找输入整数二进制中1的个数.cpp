#include<iostream>

using namespace std;

int ret_num(int n) {
	int x = 0;
	while (n) {
		if (n & 1) {
			++x;
		}
		n >>= 1;
	}
	return x;
}
int main() {
	int num;
	cin >> num;
	cout << ret_num(num) << endl;
	return 0;
}