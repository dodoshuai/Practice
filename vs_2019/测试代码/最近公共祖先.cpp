#include<iostream>
using namespace std;

int getLCA(int a, int b) {
	// write code here
	if (a == b)
		return a;
	int z = 0;
	while (a && b) {
		if(a>b) a/= 2;
		else if(a<b) b/= 2;
		if (a == b) {
			z = a;
			break;
		}
	}
	return z;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		cout << getLCA(a, b) << endl;
	}
	return 0;
}