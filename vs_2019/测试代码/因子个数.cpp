/*#include<iostream>
using namespace std;
int count(int n)
{
	int s = 1;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)//判断i是否为n的素因子
		{
			int a = 0;
			do {
				n /= i;
				a++;
			} while (n % i == 0);//根据素因子和公式此处为i的n次方
			s = s * (a + 1);

		}


	}
	if (n > 1) s = s * 2;
	return s;
}
int main() {
	int n;
	while (cin >> n) {
		cout << count(n) << endl;
	}
	return 0;
}*/
#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int n, k, i;
	while (cin >> n) {
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
			if (n % i == 0) {
				while (n % i == 0)n = n / i;
				k++;
			}
		if (n != 1)k++;
		cout << k << endl;
	}
	return 0;
}