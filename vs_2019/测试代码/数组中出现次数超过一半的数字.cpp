#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int MoreThanHalfNum_Solution(std::vector<int> numbers) {
	std::unordered_map<int, int> aa;
	for (int i = 0; i < numbers.size(); i++) {
		aa[numbers[i]] += 1;
	}
	for (int i = 0; i < numbers.size(); i++) {
		if (aa[numbers[i]] > (numbers.size() / 2)) {
			return numbers[i];
		}
	}
	return 0;
}
int main() {
	int n;
	cin >> n;
	vector<int> num(n);
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cout << MoretThanHalfNum_Solution(num) << endl;
	return 0;
}
