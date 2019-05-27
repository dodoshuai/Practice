#include<iostream>

using namespace std;

bool chkParenthesis(string A, int n) {
	// write code here
	int l = 0;
	for (int i = 0; i < n; ++i) {
		if (A[i] == '(') {
			l++;
		}
		else if (A[i] == ')') {
			l--;
		}
	}
	if (l == 0) {
		return true;
	}
	return false;
}

int main() {
	cout << chkParenthesis("((()))", 6) << endl;
	return 0;
}