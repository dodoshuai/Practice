#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> res;
		for (int i = 0; i < n; i++) {
			string a;
			cin >> a;
			if (res.empty()) {

				res.push_back(a);
			}
			else {
				int j;
				for ( j = 0; j < res.size(); j++) {
					if (res[j].size() > a.size()) {
						if (res[j].substr(0, a.size()) == a)
							break;
					}
					else if (res[j].size() < a.size()) {
						if (res[j] == a.substr(0, res[j].size()))
						{
							res[j] = a;
							break;
						}
					}
				}
				if (j == res.size()) {
					res.push_back(a);
				}

			}
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); i++) {
			cout << "mkdir -p " << res[i] << endl;
		}
	}
	return 0;
}
?
/*
//链接：https://www.nowcoder.com/questionTerminal/433c0c6a1e604a4795291d9cd7a60c7a?source=relative
//来源：牛客网

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<string> list(n);
		vector<bool> flag(n, true);
		for (int i = 0; i < n; ++i) cin >> list[i];
		sort(list.begin(), list.end());

		for (int i = 0; i < list.size() - 1; ++i)
		{
			// 1、两串相同
			// 2、前串是后串的子串，而且后串后一位是 '/'
			if (list[i] == list[i + 1]) flag[i] = false;
			else if (list[i].size() < list[i + 1].size() && \
				list[i] == list[i + 1].substr(0, list[i].size()) && list[i + 1][list[i].size()] == '/')
				flag[i] = false;
		}

		for (int i = 0; i < list.size();++i)
			if (flag[i]) cout << "mkdir -p " << list[i] << endl;
		cout << endl;
	}
	return 0;
}
*/