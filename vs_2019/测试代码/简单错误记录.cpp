#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}
int main(void) {
	string input, file;
	vector<pair<string, int>> errors;
	while (getline(cin, input)) {
		if (input.size() == 0)
			break;
		unsigned int f = input.rfind('\\');
		file = input.substr(f + 1);
		errors.push_back(make_pair(file, 1));
		for (int i = 0; i < (errors.size() - 1); i++) {
			if (errors[i].first == file) {
				errors[i].second++;
				errors.pop_back(); break;
			}
		}
	}
	stable_sort(errors.begin(), errors.end(), compare);
	int idx = 0;
	while (idx < 8 && idx < errors.size()) {
		string check = errors[idx].first;
		int t = check.find(' ');
		if (t > 16)
			errors[idx].first.erase(0, t - 16);
		cout << errors[idx].first << ' ' << errors[idx].second << endl;
		idx++;
	}
}*/
bool compare(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

int main() {
	string aa;
	vector<pair<string, int>> errors;

	while (getline(cin, aa)) {
		if (aa.size() == 0) {
			break;
		}
		int i = aa.rfind('\\');//从后遍历，找到第一个  \  的位置
		string qq = aa.substr(i+1);//截取文件名
		//cout << qq << endl;
		errors.push_back(make_pair(qq, 1));
		for (int i = 0; i < errors.size() - 1; i++) {
			if (errors[i].first == qq) {//去重
				errors[i].second++;//错误加一
				errors.pop_back();
				break;
			}
		}
		stable_sort(errors.begin(), errors.end(), compare);
		int idx = 0;
		while (idx < 8 && idx < errors.size()) {
			string check = errors[idx].first;
			int t = check.find(' ');
			if (t > 16)
				errors[idx].first.erase(0, t - 16);
		/*	int a1=errors[idx].first.find(' ');
			int a2 = errors[idx].first.rfind(' ');
			string b1 = errors[idx].first.substr(0, a1 - 1);
			string b2 = errors[idx].first.substr(a2 + 1);
			cout << b1 << ' ' << b2 << ' ' << errors[idx].second << endl;
		*/
			cout << errors[idx].first << ' ' << errors[idx].second << endl;
		
			idx++;
		}

	}

	return 0;
}
