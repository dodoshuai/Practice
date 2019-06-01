#include<iostream>
#include<math.h>
using namespace std;
bool zs(int n) {
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			break;
	}
	if (i > sqrt(n)) {
		return true;
	}
	return false;
}
int main() {
	int n;
	while(cin >> n) {
		int num = n / 2;
		int x = 0;
		for (int i = num; i > 0; --i) {
			if (zs(i) && zs(n - i)) {
				x = i;
				break;
			}

		}
		cout << x << endl;
		cout << n - x << endl;
	}
	return 0;
}