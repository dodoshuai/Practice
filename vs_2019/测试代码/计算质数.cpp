#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
int countPrimes(int n) {
	int count = 0;
	vector<bool> nums(n);
		for (int i = 2; i < n; ++i) {
			nums[i] = true;
		}

		for (int i = 2; i * i < n; ++i) {
			if (nums[i] == false)
				continue;
			for (int j = i * i; j < n; j += i) {
				nums[j] = false;
			}
		}
	
		for (int i = 2; i < n; i++) {
			
			if (nums[i] == true) {
				cout << i << endl;
				count++;
			}
		}

		
	
	return count;
}
int main() {
	int n;
	cin >> n;
	cout << countPrimes(n) << endl;
	return 0;
}