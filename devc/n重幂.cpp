#include "iostream"
#include "algorithm"
#include "fstream"
using namespace std;

/*
p[i]��ʾi��������ȫ��i���ݵĸ���
p[i] = ��p[k]*p[i-k]   1<=k<i
p[1] = 1
*/

int p[50];

int power(int n)
{
    p[1] = 1;
    for(int i=2; i<=n; i++)
        for(int k=1; k<i; k++)
            {p[i] += p[k] * p[i-k];
				printf("%d %d\n",p[i],i);
			} 
    return p[n];
}

int main()
{
    int n;
    cout << "�������������";
    cin >> n;
    cout << n << "���ݸ���Ϊ��" << power(n) << endl;
    return 0;
} 
