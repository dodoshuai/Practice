#include<iostream>
#include<string>
using namespace std;

string str_num_add(string a, string b) {
	int l = a.size()-1;
	int r = b.size()-1;
	string strs="";
	int k = l > r ? l : r;
	int flag = 0;
	while (l>=0 || r >= 0) {
		char c =  flag;
		if (l >= 0) {
			c += (a[l--]-'0');
		}
		if (r >= 0) {
			c += (b[r--]-'0');
		}
		flag = 0;
		if (c > 9) {
			c =c-10+'0';
			flag = 1;
		}
		else {
			c += '0';
		}
		strs = c + strs;
	}
	if (flag == 1) {
		strs = '1' + strs;
	}


	//cout << strs << endl;
	return strs;
}

int main() {
	string a, b;
	cin >> a;
	cin >> b;
	cout << str_num_add(a,b) << endl;
	return 0;
}