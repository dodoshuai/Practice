#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
	/*	int count = 0;
		vector<int> b;
		int max = 0;
		//b.push_back(a[0]);
		for (int i = 0; i < n; ) {
			if (b.empty()) {
				b.push_back(a[i]);
				count++;
				i++;
			}
			else {
				if (b[b.size() - 1] <= a[i]) {
					b.push_back(a[i]);
					count++;
					i++;
				}
				else {
					b.pop_back();
					count--;
				}
			}
			if (max < count) {
				max = count;
			}
		}
		*/
		int max = 1;
		vector<int> f(n, 1);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (a[i] > a[j]) {
					f[i] = f[i]>f[j]+1?f[i]:f[j] + 1;
				}
			}
			if (max < f[i])
				max = f[i];
		}
		cout << max << endl;
	}

	return 0;
}