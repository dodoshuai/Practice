#include<iostream>
using namespace std;

int binInsert(int n, int m, int j, int i) {
	int num = 0;
	for (int l = 0; l <= i-j; ++l) {
		if ((m >> l) & 1) {
			num = 1;
		}
		num <<= l + j;
		cout <<"num="<< num << endl;
		n |= num;
		num = 0;
	}
	// write code here
	return n;
}
int main(){
	int n, m, j, i;
	cin >> n >> m >> j >> i;
	cout<<binInsert(n, m, j, i)<<endl;
	return 0;
}