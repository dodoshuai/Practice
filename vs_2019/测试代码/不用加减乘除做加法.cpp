#include<iostream>
using namespace std;
int Add(int num1, int num2)
{
	//int num3 = 0;
	while (num2!=0) {
		int a = num1 ^ num2;
		int b = (num1 & num2)<<1;
		num1 = a;
		num2 = b;
	}
//	cout << num1 << endl;
	return num1;
}
/*int Add(int num1, int num2)
{
	int num3 = 0;
	int i = 0;
	while (num1||num2) {
		int a = num1 & (1<<i);
		int b = num2 | (1 << i);
		int c = a ^ b;
		int d = (a & b) << 1;
		num1 = a;
		num2 = b;
		i++;
	}
	//	cout << num1 << endl;
	return num1;
}
*/
int main() {
	int a, b;
	cin >> a >> b;
	Add(a, b);
	return 0;
}