#include<iostream>
#include<string>
using namespace std;

int main() {
	string s;
	string p;
	cin >> s;
	cin >> p;
	int count=0;
	for (int i = 0; i <= s.size(); ++i) {
		string str = s;
		str.insert(i, p);
		int left = 0;
		int right = str.size()-1;
		while(left < right) {
			if (str[left] != str[right]) {
				break;
			}
			left++;
			right--;
		}
		if (left >= right) {
			count++;
		}
	}
	cout << count << endl;
	
	return 0;
}