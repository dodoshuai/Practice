#include<iostream>
using namespace std;
int main() {
	
	double a, b;
	while (cin >> a >> b) {
		if (a > (b * 3.14 * 2)) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
	return 0;
}