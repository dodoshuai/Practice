#include<iostream>
using namespace std;
unsigned int sg(unsigned int n) {
	if (n < 10) {
		return n;
	}
	unsigned 	int x=0;
	while (n) {
		x += (n % 10);
		n /= 10;
	}
//	cout << x << endl;
	return sg(x);
}

int main() {
	unsigned int n;
	while(cin >> n)
	cout << sg(n) << endl;
	
/*	string s;
	while (cin >> s) {
		int num = 0;
		for (int i = 0; i < s.size(); ++i) {
			num += s[i] - 48;
		}
		cout << sg(num) << endl;
	}
	*/
	return 0;
}