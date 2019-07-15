//#include<iostream>
/*#include<stdio.h>
//using namespace std;
int main()
{
	long long der[21] = { 0,0,1 }, fun[21] = { 0,1,2 };
	int i, n;
	for (i = 3; i < 21; i++)
	{
		der[i] = (i - 1) * (der[i - 2] + der[i - 1]);
		fun[i] = i * fun[i - 1];
	}
	for (int i = 0; i < 21; i++) {
	//	cout << der[i] << endl;
		printf("%lld ", der[i]);
	}
	printf("\n");
	for (int i = 0; i < 21; i++) {
	//	cout << fun[i] << endl;
		printf("%lld ", fun[i]);
	}
	printf("\n");

	while (~scanf_s("%d", &n))
	{
		printf("%.2f%c\n", 1.0 * der[n] / fun[n] * 100, '%');
	}
	return 0;
}
*/
//第二步，放编号为k的元素，这时有两种情况：把它放到位置n，那么，对于剩下的n-1个元素，
	//由于第k个元素放到了位置n，剩下n-2个元素就有D(n-2)种方法；
	//第k个元素不把它放到位置n，这时，对于这n-1个元素，有D(n-1)种方法；
	//综上得到递推公式，可以发现可以用递归来做；
	//D(n) = (n-1) [D(n-2) + D(n-1)]

/*针对错排算法， 为什么要(n - 1)[D(n - 2) + D(n - 1)]
首先n - 1是第一个选择的数据的错位可能，
在排序完第一个选择的数据后，我们面临两种选择，因为第一个选择的数据占据了一个不属于他的位置，
那该位置原本的数据就肯定是一个错排数据，但该数据有两种选择
1.占据第一个数据的空位--n - 2个数据
2.不占第一个数据的空位，将自己当做是以第一个数据空位为位置的数据进行排序-- - n - 1个数据
*/
#include<iostream>
using namespace std;

int main() {
	int n;
	long long a[21] = { 0,0,1 }, b[21] = { 1,1,2 };
	while (cin >> n) {
		for (int i = 3; i <= n; i++) {
			b[i] = i * b[i - 1];
			a[i] = (i - 1) * (a[i - 1] + a[i - 2]);
	//		cout << "a[i]=" << a[i] << endl;
	//		cout << "b[i]=" << b[i] << endl;

		}
	//	cout << 1.0 * a[n] / b[n]*100 << endl;
		printf("%.2f%c\n", 1.0 * a[n] / b[n] * 100, '%');

	}
	return 0;
}

