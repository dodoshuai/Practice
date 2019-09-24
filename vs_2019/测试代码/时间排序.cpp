#include<iostream>
#include<vector>
using namespace std;

int main() {
	int n;
	int m;
	while (cin >> n >> m) {
		vector<int> ns(n, 0);
		vector<pair<int, int>> aa;
		for (int i = 0; i < m; i++) {
			int q, p;
			cin >> q >> p;
			aa.push_back(make_pair(q, p));
		}
		for (int i = 0; i < aa.size(); i++) {
			ns[aa[i].first] = aa[i].second;
		}
		
	}

}