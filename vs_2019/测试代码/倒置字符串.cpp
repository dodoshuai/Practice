#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){

	string str;
	while (getline(cin, str)) {
		vector<string> strs;
		int n = str.size();
		int begin = 0;
		int last = 0;
		int count = 0;
		for (int i = 0; i < n; ++i) {
			
			if (str[i] !=' ') {
				if (count == 0)
					begin =i;
				count++;
			}
			else if (count != 0 && str[i] == ' ') {
				strs.push_back(str.substr(begin, count));
				count = 0;
			}
		}
		if (count != 0) {
			strs.push_back(str.substr(begin, count));
		}
		str = "";
		for (int i = strs.size()-1; i >= 0; --i) {
			if (i != strs.size() - 1) {
				str += " ";
			}
			str += strs[i];		
		}
		cout << str << endl;
	}


	return 0;
}
