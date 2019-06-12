#include<iostream>
#include<string>
using namespace std;

int main(){
	string str;
	while (cin >> str) {
		int str_num[256] = { 0 };
		for (int i = 0; i < str.size(); ++i) {
			str_num[str[i]]++;
		}
		int l;
		for ( l = 0; l < str.size(); ++l) {
			if (str_num[str[l]] == 1) {
				cout << str[l] << endl;
				break;
			}
		}
		if(l==str.size())
		cout << -1 << endl;
	}
	return 0;
}