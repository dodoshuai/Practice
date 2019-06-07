#include<iostream>
#include<math.h>
using namespace std;
int count(int n) {
	int sum = 0;
	for (int i = 1; i < n; ++i) {
		int nums = 0;
		for (int j = 1; j < sqrt(i); ++j) {
			if (i % j == 0) {
				nums = nums + j + i / j;
			}
		}
		//nums = nums - i;
		if (nums == 2 * i)
			sum += 1;
	}
	return sum;
}
int main() {
	int n;
	while(cin >> n)
	cout << count(n) << endl;
	return 0;
}