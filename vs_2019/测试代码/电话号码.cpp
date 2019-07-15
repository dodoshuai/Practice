#include<iostream>
//#include<map>
#include <unordered_map>
#include<string>
#include<set>
using namespace std;
int main() {
	unordered_map<char, char> dic;
	dic.emplace('A', '2');
	dic.emplace('B', '2');
	dic.emplace('C', '2');
	dic.emplace('D', '3');
	dic.emplace('E', '3');
	dic.emplace('F', '3');
	dic.emplace('G', '4');
	dic.emplace('H', '4');
	dic.emplace('I', '4');
	dic.emplace('J', '5');
	dic.emplace('K', '5');
	dic.emplace('L', '5');
	dic.emplace('M', '6');
	dic.emplace('N', '6');
	dic.emplace('O', '6');
	dic.emplace('P', '7');
	dic.emplace('Q', '7');
	dic.emplace('R', '7');
	dic.emplace('S', '7');
	dic.emplace('T', '8');
	dic.emplace('U', '8');
	dic.emplace('V', '8');
	dic.emplace('W', '9');
	dic.emplace('X', '9');
	dic.emplace('Y', '9');
	dic.emplace('Z', '9');
	int n;
	while (cin >> n) {
		set<string> res;
		//接收
		for (int i = 0; i < n; i++) {
			string c;
			cin >> c;
			string str = "";
			for (int j = 0; j < c.size(); j++) {
				if (isdigit(c[j])) {
					str += c[j];
				}
				else if (isupper(c[j])) {
					str += dic[c[j]];
				}
				
		}
		//处理字符串
			str = str.substr(0, 3) + "-" + str.substr(3);
		//	res[i] = str;
			res.emplace(str);
		}
		//输出
		for (auto & phone : res) cout << phone << endl;
		cout << endl;
		}
	return 0;
}