#include<iostream>
#include<vector>
#include<string>
using namespace std;
int* abc(int x,int y,vector<int> &nums,int *a) {

	for (int i = 0; i <4; ++i) {
		a[i] = nums[i+x];
	}
	return a;
}

int main() {
	int n;
	while (cin >> n) {


		vector<int> nums(n + 1, 0);
		for (int i = 1; i <= n; ++i) {
			nums[i] = i;
		}
		string str1;
		cin >> str1;
		int a[4];
		int t, d;
		t = 1;
		d = 4;
	//	for (int i = 0; i < 4; ++i) {
	//		a[i] = nums[i+1];
	//	}
		if (nums.size() > 4)
		abc(t, d, nums, a);
		int top = 1;
		for (int i = 0; i < str1.size(); ++i) {
			if (str1[i] == 'U') {
				top -= 1;
				if (top == 0) {
					top = n;

					d = top;
					t = d - 3;
					if(nums.size()>=4)
					abc(t, d, nums, a);
				}
				else if (top < t) {
					t = top;
					d = top + 3;
					if (nums.size() >= 4)
					abc(t, d, nums, a);
				}
				else if (top >= t && top <= d) {

				}

			}
			else if (str1[i] == 'D') {
				top += 1;
				if (top == n + 1) {
					top = 1;
					t = top;
					d = t + 3;
					if (nums.size() >= 4)
					abc(t, d, nums, a);
				}
				else if (top > d) {
					d = top;
					t = d - 3;
					if (nums.size() >= 4)
					abc(t, d, nums, a);
				}
				else if (top > t && top <= d) {

				}
			}
		}
		if (nums.size() <= 4) {
			for (int i = 1; i < nums.size(); ++i) {
				if (i != nums.size() - 1)
					cout << nums[i] << " ";
				else {
					cout << nums[i] << endl;
				}
			}
		}
		else {
			for (int i = 0; i < 4; ++i) {
				if (i != 3)
					cout << a[i] << " ";
				else {
					cout << a[i] << endl;
				}
			}
		}
		cout << top << endl;
	}
        
	return 0;
}