#include<iostream>
#include<string>
using namespace std;

int main() {
	string s = "";
	string arr = "0123456789ABCDEF";
	int a;
	int n;
		cin >> a>>n ;
		while (a) {
			if (a < 0) {
				a = -a;
				cout << "-";
			}
			s = arr[a %n]+s;
			a /= n;
		}
		cout << s << endl;

	return 0;
}