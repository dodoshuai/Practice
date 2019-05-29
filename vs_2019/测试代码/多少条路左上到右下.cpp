/*#include<iostream>
//#include<vector>
using namespace std;

int main() {

	int n;
	int m;
	cin >> n >> m;
	n = n + 1;
	m = m + 1;
	int**a = new int* [n];
	for (int i = 0; i < n; ++i)
		a[i] = new int[m];

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i == 0 && j == 0) {
				a[i][j] = 1;
				continue;
			}
			int x = 0;
			if (i > 0) {
				x += a[i - 1][j];
			}
			if (j > 0) {
				x += a[i][j - 1];
			}
			a[i][j] = x;
			//cout <<"["<< i<<" ]["<<j<<"]"<<a[i][j] << endl;
		}
	}
	cout << a[n-1][m-1] << endl;
	return 0;
}
*/
#include<iostream>
#include<vector>
//#include<vector>
using namespace std;
int uniquePaths(int m, int n) {
	vector<vector<int>> num(n, vector<int>(m, 1));
	for (int i = 1; i < num.size(); i++) {
		for (int j = 1; j < num[i].size(); j++) {
			num[i][j] = num[i - 1][j] + num[i][j - 1];
		}
	}
	return num[n - 1][m - 1];
}
int main() {
	int n, m;
	while (cin >> n >> m) {
		cout << uniquePaths(m + 1, n + 1) << endl;
	}
	return 0;
}