#include<iostream>
#include<vector>
using namespace std;

vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) {
	// write code here
	vector<int> res;
	int i = 0, j = 0;
	int col, raw;
	int a = n-1;
	int b = m-1;
	int c = 0;
	int d = 0;
	while (a>=c&&b>=d) {
	for (int i = c;i<=a;i++) {
		res.push_back(mat[d][i]);
	}
	if(b>d)
	for (int i=d+1; i <=b; i++) {
		res.push_back(mat[i][a]);
	}
	if(c<a&&b>d)
	for (int i=a-1; i>=c; i--) {
		res.push_back(mat[b][i]);
	}
	if(d+1<b&&c<a)
	for (int i=b-1; i >=d+1; i--) {
		res.push_back(mat[i][c]);
	}
	a--;
	b--;
	c++;
	d++;
}	
	return res;
}


int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> mat;
	for (int i = 0; i < n; i++) {
		vector<int> x;
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			x.push_back(a);
		}
		mat.push_back(x);
	}
	vector<int> res = clockwisePrint(mat, m, n);
	for (int i = 0; i < res.size(); i++) {
		cout << " " << res[i];
	}
	cout << endl;
	return 0;

}