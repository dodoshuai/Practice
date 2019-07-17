#include<iostream>
#include<set>
#include<string>

using namespace std;
int main() {

	string a, b;
	//set<char, int> s;

	while (cin >> a >> b) {
		int s1[27] = { 0 };
		int s2[27] = { 0 };
		for (int i = 0; i < a.size(); i++) {
			s1[a[i] - 'A'] += 1;
		} 
		for(int i=0;i<b.size();i++){
			s2[b[i] - 'A'] += 1;
		}
		int j;
		for (j = 0; j <27; j++) {
		//	if (s1[j] < s2[j])
			//	break;
			cout << j << "=" << s1[j] << endl;
		}
		for (j = 0; j < 27; j++) {
			cout << j << "=" << s2[j] << endl;
		}
		for (j = 0; j < 27; j++) {
				if (s1[j] < s2[j])
					break;
		}
		if (j != 27) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}


	return 0;
}