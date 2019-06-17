#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<vector<int>> res;
vector<vector<int>>nums;
vector<vector<int>> best;
int dg(int x, int y) {
	nums.push_back({x,y});
	res[x][y] = 1;
	if (x == n - 1 && y == m - 1) {
		if (best.empty() || nums.size() < best.size())
				best = nums;
		return 0;
	}
	
	else {
		if(x-1>=0&&res[x-1][y]==0)
		dg(x-1, y );
		if(x+1<n&& res[x + 1][y] == 0)
		dg(x+1, y);
		if(y-1>=0&& res[x ][y-1] == 0)
		dg(x, y-1);
		if(y+1<m&& res[x][y+1] == 0)
		dg(x, y+1);
		res[x][y] = 0;
		nums.pop_back();
		return 0;

	}

}

int main() {

	while (cin >> n >> m) {
		res= vector<vector<int>>(n, vector<int>(m, 0));
		best.clear();
		nums.clear();
		for (int i = 0; i < n; ++i) {

			for (int j = 0; j < m; ++j) {

				cin >> res[i][j];

			}
		}
		dg(0, 0);
		for (auto i : best)
			cout << '(' << i[0] << ',' << i[1] << ')' << endl;
	}
	return 0;
}