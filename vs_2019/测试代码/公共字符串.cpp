#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	string a, b;
	while (getline(cin, a))
	{ 
		cin >> b;
		for (int i = 0; i < b.size(); ++i) {
			for(int j=0;j<a.size();++j){
				if (b[i] == a[j])
					a.erase(a.begin()+j);
			}
		}
		cout << a << endl;
	}
	return 0;
}
