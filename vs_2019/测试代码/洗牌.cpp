#include<iostream>
#include<vector>
using namespace std;
void math_abc(vector<int>& abc) {
	int len = abc.size();
	int x = abc.size() / 2;
	vector<int> cba;
	for (int i = 0; i < x; ++i) {
		cba.push_back(abc[i]);
		cba.push_back(abc[i + x]);
	}
	abc = cba;

}


int main() {
	int n = 0;
	cin >> n;
	//	vector<vector<int>> res;
	for (int i = 0; i < n; ++i) {
		int x;
		int k;
		//cout << "x=";
		cin >> x >> k;
		vector<int> num1(2 * x);
		for (int j = 0; j < x * 2; ++j) {
			//	cout << "num1=";
			cin >> num1[j];
		}
		while (k) {
			math_abc(num1);
			k--;
		}
		for (int j = 0; j < num1.size(); ++j) {
			if (j != num1.size() - 1)
				cout << num1[j] << " ";
			else cout << num1[j];
		}
		cout << endl;

	}

	/*
	for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j < res[i][0]; ++j) {
				math_abc(res[i]);
			}
		}
	*/
	/*	for (int i = 0; i < res.size(); ++i) {
			for (int j = 0; j <res[i].size() ; ++j) {
				if (i != 0 || j != 0) {
					cout << " ";
				}
				cout << res[i][j];
			}
		}
		cout << endl;
	*/
	return 0;
}
