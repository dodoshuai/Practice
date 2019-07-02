#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int finbnq(int n) {
	vector<int> qq(2);
	qq[0] = 1;
	qq[1] = 1;
	for (int i = 2; i <= n; ++i) {
		int a = qq[i - 2] + qq[i - 1];
		if (a > 9999) {
			a = a - 10000;
		}
		qq.push_back(a);
	}
	return qq[qq.size() - 1];
}
string numToStr(int i)
{
	stringstream ss;
	ss << i;
//	cout << i;
	return ss.str();
}
int main() {
	int n;
	
	while (cin >> n) {
		string str = "";
		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		for (int i = 0; i < n; ++i) {
			int num = finbnq(nums[i]);
			if (num < 10) {
				str += "000";
				//str += numToStr(num);
			}
			else if (num < 100) {
				str += "00";
			}
			else if (num < 1000) {
				str += "0";
			}
			str += numToStr(num);
		}
		cout << str << endl;
	}
	return 0;
}