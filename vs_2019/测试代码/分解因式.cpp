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
���ӣ�https://www.nowcoder.com/questionTerminal/0f6976af36324f8bab1ea61e9e826ef5?toCommentId=26412
��Դ��ţ����

#include <iostream>
using namespace std;
int main()
{
	int a = 0, i = 0;
	while (cin >> a)
	{
		cout << a << " = ";
		i = 2;
		while (1)   //�ҵ���һ������������������Ϊ�˸�ʽ�Ĳ���
		{
			if (a % i == 0)
			{
				cout << i;
				a = a / i;
				break;
			}
			i++;
		}
		while (a != 1)   //�ҵ�ʣ���������������
		{
			i = 2;
			while (1)
			{
				if (a % i == 0)
				{
					cout << " * " << i;
					a = a / i;            //aһֱ�ڲ��ϵؼ�С
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