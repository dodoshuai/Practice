#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checkInclusion(string s1, string s2) {
	if (s1.size() == 0) return 1;
	if (s2.size() == 0 || s1.size() > s2.size()) return 0;
	vector<int> v1(128, 0), v2(128, 0);
	for (int i = 0; i < s1.size(); i++) { v1[s1[i]]++; v2[s2[i]]++; }
	if (v1 == v2) return 1;
	for (int i = s1.size(); i < s2.size(); i++) {
		v2[s2[i]]++;
		v2[s2[i - s1.size()]]--;
		if (v1 == v2) return 1;
	}
	return 0;
}
int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;
	cout << checkInclusion(s1, s2) << endl;

	return 0;
}