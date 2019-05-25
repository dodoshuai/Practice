#include<iostream>
#include<string>
#include <sstream>
using namespace std;
int StrToInt(string str) {
	//stringstream s;
	//s << str;
	//int x;
	//s >> x;
	//return x;
	if (str.size() <= 0) {
		return 0;
	}
	int flag = 0;
	int x = 0;
	int len = str.size();
	if (str[0] == '-')
	{
		flag = -1;
	}
	else if (str[0] == '+') {
		flag = 1;
	}
	else if (str[0]<'0' || str[0]>'9')
		return 0;
	if (flag != 0) {
		for (int i = 1; i < len; ++i) {
			if (str[i]<'0' || str[i]>'9') {
				return 0;
			}
			x = x * 10 + str[i] - '0';
		}
		x = x * flag;
	}
	else {
		for (int i = 0; i < len; ++i) {
			if (str[i]<'0' || str[i]>'9') {
				return 0;
			}
			x = x * 10 + str[i] - '0';
		}
	}
	return x;

}
int main() {
	string str;
	cin >> str;
	cout << StrToInt(str) << endl;
	return 0;
}