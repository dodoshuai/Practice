#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
/*int lengthOfLongestSubstring(string s) {
	string s1;
	string s2;
	for (int i = 0; i < s.size(); i++) {
		if (s1.find(s[i]) == s.npos) {
			s1 += s[i];
		}
		else {
			if (s1.size() > s2.size()) {
				s2 = s1;
				s1 =""+s[i];
			}
		}
	}
	if (s1.size() > s2.size()) {
		s2 = s1;
		s1 = "";
	}
	return s2.size();

}
*/
int lengthOfLongestSubstring(string s) {
	int a[256] = { 0 };
	int left=0;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		/*m[s[i]] < left，我们用一个例子来说明，当输入字符串为"abbca"的时候，
		当i=4时，也就是即将要开始遍历最后一个字母a时，此时哈希表中a对应1，b
		对应3，c对应4，left为2，即当前最长的子字符串的左边界为第二个b的位置，
		而第一个a已经不在当前最长的字符串的范围内了，那么对于i=4这个新进来
		的a，应该要加入结果中，而此时未被更新的哈希表中a为1，不是0，如果不
		判断它和left的关系的话，就无法更新结果，那么答案就会少一位，所以
		需要加m[s[i]] < left。
		*/
		if (a[s[i]] == 0||a[s[i]]<left)
		{
			res = max(res, i - left + 1);
		}
		else {
			left = a[s[i]];
		}
		a[s[i]] = i+1;

	}
	return res;
}
int lengthOfLongestSubstring(string s) {
	vector<int> a(256, -1); 
	int left = -1;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		left = max(left, a[s[i]]);//左节点更新到最新的重复节点的上一个节点
		a[s[i]] = i;				//存储当前字符的最新节点
		res = max(res, i - left);
	}
	return res;
}
int lengthOfLongestSubstring(string s) {
	set<int> t;
	int left = 0, right = 0;
	int res = 0;
	for (int i = 0; i < s.size(); i++) {
		if (t.find(s[right]) == t.end()) {
			t.insert(s[right++]);
			res = max(res, (int)t.size());
		}
		else {
			t.erase(s[left++]);
		}
		return res;
	}

}
int main() {
	string str;
	while (cin >> str) {
		cout << lengthOfLongestSubstring(str) << endl;
	}

	return 0;
}