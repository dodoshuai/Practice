#include<iostream>
#include<string>
using namespace std;

int main() {
	string str1;
	while (getline(cin,str1)) {
		for (int i = 0; i < str1.size(); i++) {
			if (str1[i] >= 'A' && str1[i] <= 'Z') {
				str1[i] = (str1[i] - 'A' - 5+26) % 26 + 'A';
			}
		}
		cout << str1 << endl;
	}
	

	return 0;
}