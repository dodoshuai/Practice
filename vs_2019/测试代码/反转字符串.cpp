#include<iostream>
#include<string>
using namespace std;
string reverseStr(string s, int k) {
	for (int i = 0; i < s.size(); ++i) {
		int x = 0;
		int y = 0;
		if ((i + 1) % (2 * k) == 0) {
			x = i - 2 * k + 1;
			y = k;

		}
		else if ((i + 1) % (2 * k) >= k) {
			x = i - (i + 1) % (2 * k) + 1;
			y = k;

		}
		else {
			x = i - (i + 1) % (2 * k) + 1;
			y = (i + 1) % (2 * k);

		}

		for (int j = 0; j < y; ++j) {
			int c = s[x];
			s[x] = s[x + k - j - 1];
			s[x + k - j - 1] = c;
		}
	}

	return s;
}
int main() {
	string s;
	int k;
	cin >> s;
	cin >> k;
	cout << reverseStr(s, k) << endl;
	return 0;
}