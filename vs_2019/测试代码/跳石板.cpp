#include<iostream>
#include<math.h>
#include<vector>
using namespace std;/*
bool zs(int n) {
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			break;
	}
	if (i > sqrt(n)) {
		return true;
	}
	return false;
}
int main() {
	int n, m;
	cin >> n >> m;
	if (zs(n)) {
		cout << -1 << endl;
	}
	else {


		int x = n;
		int num = 0;
		while (x < m) {
			
			for (int i = 2; i <= x / 2; ++i) {
				if (x % i == 0) {
					if (x + x / i > m) {
						if (num == 0) {
							cout << -1 << endl;
							return 0;
						}
						if (x + i == m) {
							++num;
							x += i;
						}
						continue;
					}
					else if (x + x / i + 1 == m) {
						continue;
					}
					else {
						++num;
						x += x / i;
						break;
					}
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}*/

void getys(int n, vector<int>& ys) {
	for(int i=2;i<=sqrt(n);++i){
		if (n % i == 0) {
			ys.push_back(i);
			if(n/i!=i)
			ys.push_back(n / i);
		}
	}
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> res(m + 1, 0);
	res[n] = 1;
	int x = n;
	for (int i = x; i < m; ++i) {
		vector<int> ys;
		if (res[i] == 0)//»•∂‡”‡÷µ
			continue;
		getys(i, ys);
		for (int j = 0; j < ys.size(); ++j) {
			if ((ys[j] + i)<= m && res[ys[j] + i] != 0) {
				res[ys[j] + i] =( res[ys[j] + i] > res[i] + 1) ? (res[i] + 1) : res[ys[j] + i];
			}
			else if((ys[j]+i)<=m){
				res[ys[j] + i] = res[i] + 1;
			}

		}

	}
	if (res[m] == 0)
		cout << -1 << endl;
	cout << res[m]-1 << endl;


	return 0;
}