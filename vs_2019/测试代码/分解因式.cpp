#include <iostream>
#include<math.h>
using namespace std;
int main() {
	int n, k, i;
	while (cin >> n) {
		cout << n << "=";
		k = 0;
		for (i = 2; i <= sqrt(n); i++)
			if (n % i == 0) {
				
				while (n % i == 0) {
					if (k != 0) {
						cout << "*";
					}
					cout << i;
					n = n / i;
					k++;
				}
				
				
			}
		if (n != 1) {
			if (k != 0) {
				cout << "*";
			}
			cout  << n;
		}
			
	//	cout << k << endl;
		cout << endl;
	
	}
	return 0;
}
/*
链接：https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5?toCommentId=26412
来源：牛客网

#include <iostream>
using namespace std;
int main()
{
	int a = 0, i = 0;
	while (cin >> a)
	{
		cout << a << " = ";
		i = 2;
		while (1)   //找到第一个可以整除的素数，为了格式的操作
		{
			if (a % i == 0)
			{
				cout << i;
				a = a / i;
				break;
			}
			i++;
		}
		while (a != 1)   //找到剩余可以整除的素数
		{
			i = 2;
			while (1)
			{
				if (a % i == 0)
				{
					cout << " * " << i;
					a = a / i;            //a一直在不断地减小
					break;
				}
				i++;
			}
		}
		cout << endl;
	}
	return 0;
}
*/