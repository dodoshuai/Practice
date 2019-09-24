#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<vector<int>> res;
		vector<vector<int>> nums;
		for (int i = 0; i < n; i++) {
			vector<int> a(m, i == 0 ? 1 : 0);
			a[0] =i==0?0:1;
			res.push_back(a);
			nums.push_back(a);
		}
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			res[x-1][y-1] = -1;
		}

		res[0][0]=res[n-1][m-1] = 0;
		nums[0][0] =nums[n-1][m-1]= 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << " " << res[i][j];
			}
			cout << endl;
		}


		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				//cout << " " << res[i][j];
				if ((i != n - 1 && j != m - 1) && res[i][j] == -1) {

				}
				else {
					if (i > 0) {
						if (res[i - 1][j] == -1)
							res[i][j] += 0;
						else
							res[i][j] += res[i - 1][j];
					}
					if (j > 0) {
						if (res[i][j - 1] == -1)
							res[i][j] += 0;
						else
							res[i][j] += res[i][j - 1];
					}
				}
				if (i > 0) {
					nums[i][j] += nums[i - 1][j];
				}
				if (j > 0) {
					nums[i][j] += nums[i][j - 1];
				}
			}
		}
		cout << "nums=" << nums[n - 1][m - 1] << endl;
		cout << "res=" << res[n - 1][m - 1] << endl;
		float a = (float)res[n - 1][m - 1] / nums[n - 1][m - 1];
		printf("%0.2f\n", a);

		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				cout << " " << res[i][j];
			}
			cout << endl;
		}
	}

	return 0;
}
/*
17 16 20
14 7
17 5
10 16
4 12
3 5
7 5
9 6
7 7
3 5
6 5
5 16
9 9
4 4
14 13
9 1
4 8
8 12
4 16
3 8
10 6*/