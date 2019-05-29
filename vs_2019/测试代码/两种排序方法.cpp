#include<iostream>
#include<stdio.h>
#include<cstring>
#include<vector>
using namespace std;

int main() {
	int n;
	char strs[100][105];
	cin >> n;
	//vector<char *> strs(n);
	for (int i = 0; i < n; ++i) {
		cin >> strs[i];
	}
	int x=0;
	int y=0;
	for (int i = 1; i < n; ++i) {
		if (strcmp(strs[i], strs[i - 1]) < 0) {
			x = 1;
		}
		if (strlen(strs[i]) < strlen(strs[i - 1])) {
			y = 1;
		}
	}
	string ret;
	if (x == 1 && y == 1) {
		ret = "none";
	}
	else if (x == 1) {
		ret = "lengths";
	}else if (y == 1) {
		ret = "lexicographically";
	}
	else {
		ret = "both";
	}
	cout << ret << endl;

	return 0;
}