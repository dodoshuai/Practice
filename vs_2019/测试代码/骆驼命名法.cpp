#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string str;
	while (cin >> str) {
		string str1="";
		int flag = 0;
		for (int i = 0; i < str.size(); i++) {
			if (i > 0 &&str[i - 1] == '_') {
				str1+=toupper(str[i]);
			}
			else if(str[i]!='_'){
				str1 += str[i];
			}
		//	flag++;
		}
		cout << str1 << endl;
	}
	return 0;
}