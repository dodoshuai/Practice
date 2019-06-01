#include<iostream>
#include<string>

using namespace std;

int ctoi( char s) {
	int num = 0;
	if (s == 'I') {
		num += 1;
	}
	else if (s == 'V') {
		num += 5;
	}
	else if (s == 'X') {
		num += 10;
	}
	else if (s == 'L') {
		num += 50;
	}
	else if (s == 'C') {
		num += 100;
	}
	else if (s == 'D') {
		num += 500;
	}
	else if (s == 'M') {
		num += 1000;
	}
	return num;
}
int romanToInt(string s) {
	int num = 0;
	if (s.size() <= 1) {
		return ctoi(s[0]);
	}
	//char a[]={}
	int i = 0;
	for (i = 1; i < s.size(); ++i) {
		if (s[i - 1] == 'I' && s[i] == 'V') {
			num += 4;
			++i;
		}
		else if (s[i - 1] == 'I' && s[i] == 'X') {
			num += 9;
			++i;
		}
		else if (s[i - 1] == 'X' && s[i] == 'L') {
			num += 40;
			++i;
		}
		else if (s[i - 1] == 'X' && s[i] == 'C') {
			num += 90;
			++i;
		}
		else if (s[i - 1] == 'C' && s[i] == 'D') {
			num += 400;
			++i;
		}
		else if (s[i - 1] == 'C' && s[i] == 'M') {
			num += 900;
			++i;
		}
		else {
			num += ctoi(s[i-1]);
		}
		//cout << num << endl;
	}
	if (i == s.size())
		num +=ctoi(s[s.size() - 1]);
	return num;
}
int main() {
	string a = "I";
	cout << romanToInt(a) << endl;
	return 0;
}