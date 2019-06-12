#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;

int main() {
	int max = 0;
	string str1;
	string str2;
	cin >> str1;
	cin >> str2;
	for(int i=0;i<str1.size();++i)
	str1[i] = tolower(str1[i]);
	for(int i=0;i<str2.size();++i)
	str2[i]= tolower(str2[i]);
		for (int i = 0; i < str1.size(); ++i) {
		for (int j = 0; j < str2.size(); ++j) {
			int m, n;
			n = i;
			m = j;
			int len = 0;
			while (n < str1.size() && m < str2.size()) {
				if (str1[n] != str2[m]) {
					break;
				}
				++n;
				++m;
				++len;
			}
			if (max < len) {
				max = len;
			}
		}
	}
	cout << max << endl;
	return 0;
}
