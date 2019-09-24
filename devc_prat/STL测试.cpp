#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;
void Testset()
{
    int a[] = { 5, 6, 1, 9, 8, 3, 4, 2, 7, 0 };
    set<int> s;
    for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        s.insert(a[i]);
    }

    set<int>::iterator it=s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
		cout<<endl;
    set<int>::reverse_iterator rit = s.rbegin();
    while (rit != s.rend())
    {
        cout << *rit << " ";
        rit++;
    }
}
void Testset_1()
{
    int a[] = { 5, 6, 1, 9, 8, 3, 4, 2, 7, 0 };
    set<int> s;
    int b , size , maxsize = 0;
    b = s.empty();
    size = s.size();
    maxsize = s.max_size();
    cout << b << " " << size << " " << maxsize << " ";

    for (size_t i = 0; i < sizeof(a) / sizeof(int); ++i)
    {
        s.insert(a[i]);
    }

    b = s.empty();
    size = s.size();
    maxsize = s.max_size();
    cout << b << " " << size << " " << maxsize << " ";
}
void Testset2()
{
    int a[] = { 5, 6, 1, 9, 8, 3, 4, 2, 7, 0 };
    unordered_set<int> s;
    s.insert(s.begin(), a[0]);//第二种插入
    for (size_t i = 1; i < sizeof(a) / sizeof(int); ++i)
    {
        cout<<(s.insert(a[i]).second)<<endl;;//第一种插入
        // cout<<*(s.insert(s.begin(), a[i]))<<endl;
         //cout<<aa<<endl;
    }
	//s.insert(s.begin(), 15);
    unordered_set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
}

void Testset3()
{
    int a[] = { 5, 6, 1, 9, 8, 3, 4, 2, 7, 0 };
    set<int> s;
    s.insert(s.begin(), a[0]);//第二种插入
    for (size_t i = 1; i < sizeof(a) / sizeof(int); ++i)
    {
    s.insert(a[i]);//第一种插入
       
    }
	//s.insert(s.begin(), 15);
    set<int>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it << " ";
        it++;
    }
}
int main(){
	//Testset();
	//Testset_1();
	Testset2();
	return 0;
}
