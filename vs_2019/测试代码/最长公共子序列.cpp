
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int MaxSubString(string a, string b) {
	int lena = a.size();
	int lenb = b.size();
//	int res[lena][lenb];
	vector<vector<int>> res(lena);
	for (int i = 0; i < lena; i++) {
		vector<int> a(lenb,0);
		res[i] = a;
	}
	res[0][0] = (a[0] == b[0]) ? 1 : 0;
	cout << "--------------------------" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "i=" << i;
		for (int j = 0; j < res[i].size(); j++) {
			cout << " " << res[i][j] ;
		}
		cout << endl;
	}
	for (int i = 1; i < lena; i++) {
		res[i][0] = (a[i] == b[0]) ? 1 : 0;
		res[i][0] = max(res[i - 1][0], res[i][0]);
	}
	cout << "--------------------------" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "i=" << i;
		for (int j = 0; j < res[i].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	for (int j = 1; j < lenb; j++) {
		res[0][j] = (a[0] == b[j]) ? 1 : 0;
		res[0][j] = max(res[0][j - 1], res[0][j]);
	}
	cout << "--------------------------" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "i=" << i;
		for (int j = 0; j < res[i].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	for (int i = 1; i < lena; i++) {
		for (int j = 1; j < lenb; j++) {
			res[i][j] = max(res[i - 1][j], res[i][j - 1]);
			if (a[i] == b[j])
				res[i][j] = max(res[i][j], res[i - 1][j - 1] + 1);
		}
	}
	cout << "--------------------------" << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << "i=" << i;
		for (int j = 0; j < res[i].size(); j++) {
			cout << " " << res[i][j];
		}
		cout << endl;
	}
	return res[lena - 1][lenb - 1];
}

int main() {
	string a, b;
	while (cin >> a >> b) {
		int res = MaxSubString(a, b);
		cout << res << endl;
	}
	return 0;
}