#include<iostream>

using namespace std;


int main() {
	long long  p1, p2, p3;
	int m, n;
	//nÊÇfrom£¬mÊÇto
	while (cin >> n >> m){
	p1 = 0;
	p2 = 0;
	p3 = 1;
	long long n1, n2;
	if (n > 1)
	{
		n1 = 1;
	}
	else {
		n1 = 0;
	}
	n2 = 1;
	for (int i = 2; i <= m; i++) {
		p1 += p2;
		p2 = p3;
		p3 = p1;
		cout << p1 <<" "<< p2<<" "  << p3<<" "<<p1+p2+p3 << endl;
		if (i < n)
			n1 += p1 + p2 + p3;
		if (i <= m) {
			n2 += p1 + p2 + p3;
		}
	}
	cout << "n1=" << n1 << endl;
	cout << "n2=" << n2 << endl;
	cout << n2 - n1 << endl;
}
	return 0;
}