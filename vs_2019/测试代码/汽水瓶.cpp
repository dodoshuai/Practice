#include<iostream>
using namespace std;
int math_qsp(int num) {
	int count = 0;
	while(num>=3){
		int a = num % 3;
		num= num / 3;
		count += num;
		num += a;
	}
	if (num == 2) {
		count++;
	}
	return count;
}

int main() {
	int n;
	while (cin >> n) {
		cout << math_qsp(n) << endl;
	}
}