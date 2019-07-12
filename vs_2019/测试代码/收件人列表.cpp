#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<string> strs(n,"");
		int i = 0;
		getchar();
		while (getline(cin, strs[i++])){
		
			int q = i - 1;
			if (i >= n) {
				break;
			}
			fflush(stdin);
		}
		
	//	cout << "n=" << n <<"size()="<<strs.size()<< endl;
		for (int i = 0; i < n; ++i) {
			int j;
			for ( j = 0; j < strs[i].size(); j++) {
				if (strs[i][j] == ' ' || strs[i][j] == ',') {
					break;
				}
			}
			if (i != 0) {
				cout << ", " ;
			}
			if (j == strs[i].size()) {
				cout << strs[i];
			}
			else {
					cout<<'"'<<strs[i]<<'"';
			}
		
		}
		cout << endl;
	}


	return 0;
}
