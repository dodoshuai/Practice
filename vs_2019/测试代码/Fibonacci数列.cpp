#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> nums;
	int n;
	cin >> n;
	nums.push_back(0);
	nums.push_back(1);
	for (int i = 2;; i++) {
		 nums.push_back(nums[i - 1] + nums[i - 2]);
		 if (nums[i] > n) {
			 break;
		}
	}
	/*for (int i = 0; i < nums.size(); ++i) {
		cout << nums[i] << endl;
	}
	*/
	int min = (nums[nums.size() - 1] - n) < (n - nums[nums.size() - 2]) ? (nums[nums.size() - 1] - n) : (n - nums[nums.size() - 2]);
	cout << min << endl;
	return 0;
}