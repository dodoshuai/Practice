/*#include<iostream>
#include<string>
using namespace std;

int main() {
	string a;
	string b;
	while (cin >> a >> b) {
		int a_l = a.size();
		int b_l = b.size();
		int i = 0;
		int j = 0;

		while (i < a_l && j < b_l) {
			if (a[i] == '?') {
				if ((b[j] >= '0' && b[j] <= '9') || (b[j] >= 'a' && b[j] <= 'z') || (b[j] >= 'A' && b[j] <= 'z'))
				{
					++i;
				}
				else {
					break;
				}
			}
			else	if (a[i] == '*') {
				if ((b[j] >= '0' && b[j] <= '9') || (b[j] >= 'a' && b[j] <= 'z') || (b[j] >= 'A' && b[j] <= 'z'))
				{

				}
				else {
					if ((i + 1) < a_l && a[++i] == b[j]) {
						++i;
					}
					else {
						break;
					}
				}
			}
			else {
				if (a[i] == b[j]) {
					++i;
				}
				else {
					break;
				}
						}
			++j;
		}
		if (j == b_l) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
	return 0;
}
*/
#include<string>
#include<iostream>
#include<vector>
using namespace std;
int match_string(string m_str, string w_str) //match wildcard 通配符
{
	int m_len = m_str.size();
	int w_len = w_str.size();
	vector<vector<int> > b_dp(w_len + 1, vector<int>(m_len + 1, 0));
	//多加一行一列作为初始初值所用
	b_dp[0][0] = 1;
	for (int i = 1; i <= w_len; i++)
	{
		char ch = w_str[i - 1];
		////设置每次循环的初值，即当星号不出现在首位时，匹配字符串的初值都为false
		b_dp[i][0] = b_dp[i - 1][0] && (ch == '*');
		for (int j = 1; j <= m_len; j++)
		{
			char ch2 = m_str[j - 1];
			if (ch == '*')
				b_dp[i][j] = b_dp[i - 1][j] || b_dp[i][j - 1]; //当匹配字符为*号时，状态取决于上面状态和左边状态的值
			else
				b_dp[i][j] = b_dp[i - 1][j - 1] && (ch == '?' || ch2 == ch);
		}
	}
	return b_dp[w_len][m_len];



}
 int main()
{
	string str1, str2;
	while (cin >> str1 >> str2)
	{
		int rst = match_string(str2, str1);
		if (rst == 1)
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}

}
