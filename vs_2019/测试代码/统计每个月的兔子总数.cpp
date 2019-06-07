#include<iostream>
using namespace std;
int dd_tz(int p,int p1,int p2,int m,int n) {
	//p 正常能生的兔子
	//p1 下个月能生的兔子
	//p2 刚生的兔子
	if (m == n)
		return p+p1+p2;
	p = p1+p;
	p1 = p2;
	p2 = p;
	return dd_tz(p,p1,p2,m+1,n);

	
}


int main() {
	int n;
	while(cin >> n)
	cout << dd_tz(0, 0, 1, 1,n)<<endl;
	return 0;
}