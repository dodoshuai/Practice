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
//�ڶ������ű��Ϊk��Ԫ�أ���ʱ����������������ŵ�λ��n����ô������ʣ�µ�n-1��Ԫ�أ�
	//���ڵ�k��Ԫ�طŵ���λ��n��ʣ��n-2��Ԫ�ؾ���D(n-2)�ַ�����
	//��k��Ԫ�ز������ŵ�λ��n����ʱ��������n-1��Ԫ�أ���D(n-1)�ַ�����
	//���ϵõ����ƹ�ʽ�����Է��ֿ����õݹ�������
	//D(n) = (n-1) [D(n-2) + D(n-1)]

/*��Դ����㷨�� ΪʲôҪ(n - 1)[D(n - 2) + D(n - 1)]
����n - 1�ǵ�һ��ѡ������ݵĴ�λ���ܣ�
���������һ��ѡ������ݺ�������������ѡ����Ϊ��һ��ѡ�������ռ����һ������������λ�ã�
�Ǹ�λ��ԭ�������ݾͿ϶���һ���������ݣ���������������ѡ��
1.ռ�ݵ�һ�����ݵĿ�λ--n - 2������
2.��ռ��һ�����ݵĿ�λ�����Լ��������Ե�һ�����ݿ�λΪλ�õ����ݽ�������-- - n - 1������
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

