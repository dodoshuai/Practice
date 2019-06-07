#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	string str;
	vector<string> res;
	getline(cin, str);
	//int i = str.size();
	int begin = 0;
	int last = 0;
	int len = 0;
	int flag = 0;
	for (last = 0; last < str.size();++last) {
		if (str[last] == '"') {
			flag^= 1;
		}
		
		if (str[last] != ' '||flag!=0) {
			if (len == 0) {
				if (flag != 0&&str[last]!='"')
					begin = last ;
				else 
				begin = last;
			}
			if(str[last]!='"')
			++len;
		}
		else if (str[last] == ' ' && len != 0) {
			string s;
			if (flag == 0) {
				//if (str[last - 1] == '"')
				//	s = str.substr(begin, len - 1);
			//	else
					s = str.substr(begin, len);
				res.push_back(s);
				len = 0;
			}
		}
	}
	res.push_back(str.substr(begin, len));
	cout << res.size() << endl;
	for(int i=0;i<res.size();++i)

	cout << res[i]<< endl;

	return 0;
}