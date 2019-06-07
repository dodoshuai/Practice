#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int findMinimum(int n, vector<int> left, vector<int> right) {
	// write code here
	int l = 0;
	int r = 0;
	for (int i = 0; i < n; ++i) {
		if (left[i] != 0 && right[i] != 0) {
			continue;
		}
		else {
			if (left[i] == 0) {
				r += right[i];
				right[i] = 0;
			}
			else if (right[i] == 0) {
				l += left[i];
				left[i] = 0;
			}
		}
	}
	sort(left.begin(), left.end());
	sort(right.begin(), right.end());
	int lmin = 0;
	int rmin = 0;
	int lnum = 0;
	int rnum = 0;
	for (int i = 0; i < n; ++i){
		if (lmin == 0 && left[i] != 0)
			lmin = left[i];
		if (rmin == 0 && right[i] != 0)
			rmin = right[i];
		lnum += left[i];
		rnum += right[i];
	}	
	lnum -= lmin;
	rnum -= rmin;
	int lmax = lnum + r + l + 2;
	int rmax = rnum + r + l + 2;
	return lmax>rmax?rmax:lmax;
}

int main() {
	int n;
	cin >> n;
	vector<int> left(n);
	vector<int> right(n);
	for (int i = 0; i < n; ++i)
		cin >> left[i];
	for (int i = 0; i < n; ++i)
		cin >> right[i];
	cout << findMinimum(n, left, right)<<endl;

	return 0;
}