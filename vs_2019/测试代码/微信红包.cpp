#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int getValue(vector<int> gifts, int n) {
	map<int, int> nums;
	for (int i = 0; i < n; ++i) {
		nums.insert(pair<int, int>(gifts[i], 0));
		nums[gifts[i]]++;
	}
	for (int i = 0; i < n; ++i) {
		if (nums[gifts[i]] > (n/2)){
			return gifts[i];
		}
	}
	return 0;
}