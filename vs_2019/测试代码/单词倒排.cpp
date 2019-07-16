#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string str;
	while (getline(cin, str)) {
		vector<string> s;
		bool flag=false;
	//	int left=0, right=0;
		string tmp = "";
		for (int i = 0; i < str.size(); i++) {
			if (isalpha(str[i])) {
				tmp+=str[i];
					flag=true;
			}
			else {
				if (flag == true) {
					s.push_back(tmp);
					tmp.clear();
					flag = false;
				}
			}
		}
		if (tmp.size() != 0) {
			s.push_back(tmp);
			tmp.clear();
		}
		string str1="";
		for (int i = s.size()-1; i>=0; i--) {
			str1 += s[i];
			if(i!=0)
			str1 += " ";
		}
		cout << str1 << endl;
	}

	return 0;
}