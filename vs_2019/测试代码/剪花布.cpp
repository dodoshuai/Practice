#include<iostream>
#include<string>
using namespace std; 
int main(){
	string a;
	string b;
	while (cin >> a >> b){
	int i;
	int j;
	int count = 0;
	for (i = 0, j = 0; i < a.size();) {
		if (a[i] == b[j]) {
			while (j < b.size() && a[i] == b[j]) {
				j++;
				i++;
			}
			if (j == b.size()) {
				count++;
			}
			j = 0;
		}
		else {
			i++;
		}

	}
	cout << count << endl;
	}
	return 0;
}