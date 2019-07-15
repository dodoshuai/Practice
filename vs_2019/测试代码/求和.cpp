#include<iostream>
#include<vector>
#include <algorithm> 
#include<set>
using namespace std;
vector<int> d;
int n, m;
void dfs(int index, int sum) {
	if (sum > m) {
		return;
	}
	if (sum == m) {
		int i = 0; 
		for (i = 0; i < d.size() - 1; i++) {
			cout << d[i] << " " ;
		}
		cout << d[i] << endl;
	}
	for (int i = index; i <= n; i++) {
		d.push_back(i);
		dfs(i + 1, sum + i);
		d.pop_back();
	}
}
void abc() {
	vector<vector<int>> S;
	vector < vector<int>> res;
	vector<int> a(1,0);
//	a.push_back(1);
//	a[0] += 1;
	S.push_back(a);
	for (int i = 1; i <= n; i++) {
		if (i <= m) {
			int size = S.size();
			for (int j = 0; j < size; j++) {
				vector<int> b = S[j];
				b.push_back(i);
				b[0] += i;
				S.push_back(b);
				if (b[0] == m) {
					res.push_back(b);
					//S.erase(S.begin() + j);
					S.pop_back();
				}
				else if(b[0]>m){
					S.pop_back();
				}
			}
		}
		else {
			break;
		}
		
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); i++) {
		int j;
		for ( j = 1; j < res[i].size()-1; j++) {
			cout << res[i][j] << " ";
		}
		cout <<res[i][j]<< endl;
	}

}
int main() {
//	int n, m;
	while (cin>>n>>m) {
		//dfs(1, 0);
		abc();
	}

	return 0;
}