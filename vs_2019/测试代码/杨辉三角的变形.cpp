#include<vector>
#include<iostream>
using namespace std;

int aq(int n) {
	vector<int> a(2, 0);
	a[0] = 1;

	for (int j = 2; j <=n; ++j) {
		vector<int> b;

		for (int i = 0; i < 2 * j - 1; ++i) {
			if (i == 0) {
				b.push_back(a[0]);
			}
			else if (i == 1) {
				b.push_back(a[0] + a[1]);
			}
			else if (i == a.size()) {
				b.push_back(a[i - 2] + a[i - 1]);
			}
			else if (i == a.size() + 1) {
				b.push_back(a[i - 2]);
			}
			else {
				b.push_back(a[i - 2] + a[i - 1] + a[i]);
			}
		}
	/*	cout << "-----------------------" << endl;
		for (int i = 0; i < b.size(); ++i) {
			cout << b[i] << endl;
		}
		*/
		a = b;
	}
	
	for (int i = 0; i < a.size(); ++i) {
		if (a[i] % 2 == 0) {
			return i + 1;
		}
	}
	return -1;
}
int main() {
	int n;
	cin >> n;
	cout<<aq(n)<<endl;
	return 0;
}