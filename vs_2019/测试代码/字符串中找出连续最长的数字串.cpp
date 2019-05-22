#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;
	int n = str.size();
	int begin = 0;
	int last = 0;
	string ret = "";
	for (int i = 0; i < n; ++i) {
		if (str[i] >= '0' && str[i] <= '9') {
			if (last == 0) {
				begin = i;
			}
			++last;
		}else {
			if (last != 0) {
				string new_str = str.substr(begin, last);
				if (new_str.size() > ret.size()) {
					ret = new_str;
				}
				last=0;
			}
		}
	}
	string new_str = str.substr(begin, last);
				if (new_str.size() > ret.size()) {
					ret = new_str;
				}
	cout << ret << endl;
	return 0;
}