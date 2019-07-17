#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		vector<string> s(n);
		for (int i = 0; i < s.size(); i++) {
			cin >> s[i];
		}
		string qq;
		cin >> qq;
		string qq1 = qq;
		sort(qq1.begin(), qq1.end());
		vector<string> res;
		for (int i = 0; i < s.size(); i++) {
			string temp = s[i];
			sort(temp.begin(), temp.end());
			if (temp == qq1 && s[i] != qq) {
				res.push_back(s[i]);
			}
		}
		sort(res.begin(), res.end());
		cout << res.size() << endl;
		int index;
		cin >> index;
		if (index <= res.size()) {
			cout << res[index - 1] << endl;
		}
		
	}

	return 0;
}