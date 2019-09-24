#include<iostream>

#include<vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<pair<string, string>> res;
		for (int i = 0; i < n; i++) {
			string a, b;
			cin >> a >> b;
			res.push_back(pair<string,string>(a,b));
		}
		/*for (int i = 0; i < n; i++) {
			cout << i << "=" << res[i].first << " " << res[i].second << endl;
		}
		*/
		int count = 0;
		int max = 0;
		for (int i = 0; i < res.size(); i++) {
			if (res[i].second == "connect") {
				count++;
			}else if (res[i].second == "disconnect") {
				count--;
			}
			max = max > count ? max : count;
		}
		cout << max << endl;
	}
	return 0;
}
