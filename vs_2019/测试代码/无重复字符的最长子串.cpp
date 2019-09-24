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
		/*m[s[i]] < left��������һ��������˵�����������ַ���Ϊ"abbca"��ʱ��
		��i=4ʱ��Ҳ���Ǽ���Ҫ��ʼ�������һ����ĸaʱ����ʱ��ϣ����a��Ӧ1��b
		��Ӧ3��c��Ӧ4��leftΪ2������ǰ������ַ�������߽�Ϊ�ڶ���b��λ�ã�
		����һ��a�Ѿ����ڵ�ǰ����ַ����ķ�Χ���ˣ���ô����i=4����½���
		��a��Ӧ��Ҫ�������У�����ʱδ�����µĹ�ϣ����aΪ1������0�������
		�ж�����left�Ĺ�ϵ�Ļ������޷����½������ô�𰸾ͻ���һλ������
		��Ҫ��m[s[i]] < left��
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
		left = max(left, a[s[i]]);//��ڵ���µ����µ��ظ��ڵ����һ���ڵ�
		a[s[i]] = i;				//�洢��ǰ�ַ������½ڵ�
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