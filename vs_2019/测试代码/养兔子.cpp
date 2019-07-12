#include<iostream>
#include<vector>
//#include<stdio.h>
using namespace std;
int main() {
	int n;
	while(cin >> n){
		long long q1;
		long long q2;
	q1 = 0;
	q2 = 1;
	for (int i = 1; i <= n; i++) {
		long long temp = q1 ;
		q1 = q2;
		q2 += temp;
		}
	//long long  num = q1 + q2;
	cout << q2 << endl;
	}
	return 0;
}

/*
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	long long n;
	long long child = 1;
	long long adult = 0;
	long long i = 0;
	long long temp;

	while (cin >> n)
	{
		i = 0;
		child = 1;
		adult = 0;
		while (++i <= n)
		{
			temp = child;
			child = adult;
			adult += temp;
		}

		cout << adult + child << endl;

	}
}
*/
