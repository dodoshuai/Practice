#include<iostream>
#include<string>
using namespace std;

int main() {
	double a, b, c;
	while (cin >> a >> b >> c) {
		int flag = 0;
		if (a + b > c && a - b < c) {
			if (a + c > b && a - c < b) {
				if (b + c > a && b - c < a) {
					flag = 1;
				}
			}
		}
		string str = "";
		if (flag == 1) {
			str = "Yes";
		}
		else {
			str = "No";
		}

		cout << str << endl;
	}
	return 0;
}