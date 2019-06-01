#include<iostream>
using namespace std;

int main() {
	int a;
	while (cin >> a) {
		int max = 0;
		int count = 0;
		while (a) {
			if (a & 1) {
				count++;
			}
			else {
				if (count > max) {
					max = count;
				}
				count = 0;
			}
			a >>= 1;
		}
		if (max < count) {
			max = count;
		}
		cout << max << endl;
	}
	return 0;
}