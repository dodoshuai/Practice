#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 0)
			break;
		else
		{
			cout << (int)(pow(5, n) - 4) << " " << (int) (pow(4, n) + n - 4) << endl;
		}
	}
	return 0;
}