#include<iostream>
#include<vector>
using namespace std;
int findMaxGap(vector<int> A, int n) {
	// write code here
	int max = A[0];
	int min;
	for (int i = 1; i < n; i++) {
		max = max < A[i] ? A[i] : max;
	}
	min = A[0] < A[n-1] ? A[0] : A[n-1];
	return max - min;
}
int main() {
	int n;
	cin >> n;
	vector<int> A(n);
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	cout << findMaxGap(A, n) << endl;
	return 0;
}