#include<iostream>
#include<vector>
using namespace std;
int m_zdl(int brl, int num) {
	int zz;
	if (brl >= num) {
		zz = num + brl;
	}
	else  {
		int a = num;
		int b = brl;
		while (b) {
			int r = a%b;
			a= b;
			b = r;
		}
		zz = a + brl;
	}
	return zz;
}


int main() {

	int n, br;
	while (cin >> n >> br) {


		vector<int> nums(n);
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		for (int i = 0; i < n; ++i) {
			br = m_zdl(br, nums[i]);
		}
		cout << br << endl;
	}
	return 0;
}