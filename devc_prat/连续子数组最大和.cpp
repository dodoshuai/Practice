#include<iostream>
using namespace std; 
int GetMax(int a, int b)   //�õ������������ֵ
{
    return (a) > (b) ? (a) : (b);
}

int GetMaxAddOfArray(int* arr, int sz)
{
    if (arr == NULL || sz <= 0)
        return 0;

    int Sum = arr[0];   //��ʱ���ֵ
    int MAX = arr[0];   //�Ƚ�֮������ֵ

    for (int i = 1; i < sz; i++)
    {	cout<<i<<"="<<Sum<<endl;
        Sum = GetMax(Sum + arr[i], arr[i]);   //״̬����
			
        if (Sum >= MAX)
            MAX = Sum;
    }
    return MAX;
}

int main()
{
    //int array[] = { 2, 3, -6, 4, 6, 2, -2, 5, -9 };
    int array[] = { 1, 4, -10, 9, 8, 3, -6};
    int sz = sizeof(array) / sizeof(array[0]);
    int MAX = GetMaxAddOfArray(array, sz);
    cout << MAX << endl;
    return 0;
}
