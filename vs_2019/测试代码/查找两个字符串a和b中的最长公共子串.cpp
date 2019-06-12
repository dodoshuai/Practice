#include<iostream>
#include<vector>
#include<string>
using namespace std;
string max_z_str(string a, string b) {
	string c = a.size() > b.size() ? b : a;
	string d = a.size() > b.size() ? a : b;
	int n = c.size();
	int m = d.size();
	vector<vector<int>> res(n+1);
		for (int i = 0; i < n+1; ++i)
		{
			vector<int> s1(m+1, 0);
			res[i] = s1;
		}
		int start = 0, maxlen = 0;
		for (int i = 1; i < n+1; ++i) {
			for (int j = 1; j < m+1; ++j) {
				if (c[i-1] == d[j-1]) {
					res[i][j] = res[i-1][j - 1] + 1;
					if (res[i][j] > maxlen)
					{
						maxlen = res[i][j];
						start = i - maxlen;
					}
				}
			}
		}

		return c.substr(start, maxlen);
 
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << max_z_str(s1, s2) << endl;
	}
	return 0;
}
