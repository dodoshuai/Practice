#include<iostream>
#include<string>
using namespace std;

int main() {
	string str;
	cin >> str;
	for (int i = 0; i < str.size() / 2; ++i) {
		char tmp = str[i];
		str[i] = str[str.size() - 1 - i];
			str[str.size() - 1 - i] = tmp;
	}
	cout << str << endl;



}