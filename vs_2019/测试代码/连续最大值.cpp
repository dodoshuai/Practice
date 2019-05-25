#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int maxSubArray(vector<int>& nums) {
	int res = 0;
	int sum = 0;
	res = nums[0];
	for (int i = 0; i < nums.size(); i++) {
		res = max(nums[i], res);
	}

	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum >= 0) {
			res = max(res, sum);
		}
		if (sum < 0) {
			sum = 0;
		}
	}
	return res;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cout << maxSubArray(a) << endl;
	/*for (int i = 1; i < n; ++i) {
		if (i == 1) {
			res[i] = a[i] > a[i - 1] ? a[i] : a[i - 1];
		}
		res[i] = (a[i] + res[i - 1]) > res[i - 1] ? (a[i] + res[i - 1]) : res[i - 1];
	}*/
	//cout << res[n - 1] << endl;
	return 0;
}