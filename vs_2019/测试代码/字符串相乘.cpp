/*
	给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
	示例 1:

输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:

输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string multiply(string num1, string num2) {
	string ss(num1.size() + num2.size(), '0');
//	cout << ss << endl;
	int w = 1;
	for (int i = num1.size() - 1; i >= 0; i--) {//从最后一个开始进行乘法运算
		int a = num1[i] - '0';
		int sum = 0;
		int c = 0;
		string s = "";
		for (int j = num2.size() - 1; j >= 0; j--) {//将num1的一个值和num2相乘
			int b = num2[j] - '0';
			sum = a * b + c;
			int x = sum % 10;
			s = (char)(x + '0') + s;
			c = sum / 10;
			sum = 0;
		}
		if (c != 0) {
			s = (char)(c + '0') + s;
		}

		int m = ss.size() - w;//个位，十位，百位，当做乘数是没有当做响应大小的值，得到的数值要进相应的位，
		int c2 = 0;

		for (int q = s.size() - 1; q >= 0; q--) {//将每个位的乘数相加（确保大的进位，例如个位的乘数和十位的乘数）
			int l = ss[m] - '0';
			int k = s[q] - '0';
		//	int y = ss[m] - '0' + s[q] - '0';
			int y = l + k+c2;
			c2 = 0;
			if (y > 9) {
				y = y - 10;
				c2 = 1;
			}
			ss[m--] = (char)(y + '0');
		}
		if (c2 != 0) {
			ss[m]=(char)(c2+'0');
		}
		w++;
	}
//	cout << ss << endl;
	//消去字符串首的‘0’
	string s3 = "0";
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] != '0') {
			s3=ss.substr(i, ss.size() - i);
			break;
		}
	}
	return s3;
}
int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	cout << multiply(s1, s2) << endl;
	return 0;
}