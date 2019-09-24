/*
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	int n;
	while (cin >> n) {
		//vector<string> strs(n);
		for (int i = 0; i <n; i++) {
			int k;
			string s;

			cin >> k;
			cin >> s;
			if (k < 11) {
				cout << "NO" << endl;
			}
			else {
			
							if (s.find('8') != s.npos) {
					int i = s.find('8');
					string s1 = s.substr(i, k - i);
					if (s1.size() < 11) {
						cout << "NO" << endl;
					}
					else if (s1.size() >= 11) {
						cout << "YES" << endl;
					}
				}
				else {
					cout << "NO" << endl;
				}
			}
		}
	}

	return 0;
}
*/
/*#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void quicksort(vector<int> &nums,vector<int> &b,int left,int right) {
	if (left > right)
		return;
	int temp = nums[left];
	int temp2 = b[left];
	int i = left;
	int j = right;
	while (i != j) {
		while (nums[j] >= temp && i < j)
			j--;
		while (nums[i] <= temp && i < j)
			i++;
		if (i < j) {
			Swap(nums[i], nums[j]);
			Swap(b[i], b[j]);
		}
	}
	nums[left] = nums[i];
	b[left] = b[i];
	nums[i] = temp;
	b[i] = temp2;
	quicksort(nums,b,left, i - 1);
	quicksort(nums,b,i + 1, right);
}
int main() {
	int n;
	while(cin >> n) {
		vector<int> a(n);
		vector<int> b(n);
				int num = 0;
					for (int i = 0; i < n; i++) {
			cin >> a[i] >> b[i];
			num += a[i];
		}
					quicksort(b,a , 0, b.size()-1);
					int max = 0;
			int q=0;
			int pp = a.size() - 1;
			for (int i = 0; i < num/2; i++) {
				int a1 = 0;
				int a2 = 0;
				if (a[q] != 0) {
					a1 = b[q];
					a[q]--;
				}
				else {
					q++;
					a1 = b[q];
					a[q]--;
				}
			
				if (a[pp] != 0) {
					a2 = b[pp];
					a[pp]--;
				}
				else {
					pp--;
					a1 = b[pp];
					a[pp]--;
				}
				int qaq = a1 + a2;
				if (qaq > max) {
					max = qaq;
				}
			}		
		cout << max << endl;
		
	}
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
int main() {
	int n;
	while (cin >> n) {
		int k;
		for (int z = 0; z < n; z++) {
			cin >> k;
			vector<int> s1;
			for (int i = 0; i < k; i++) {
				int x;
				cin >> x;
				s1.push_back(x);
			}
			int aa = 0;
			int bb = 0;
			sort(s1.begin(), s1.end());\

			for (int i = s1.size()-1; i >=0; i -=2)
			{
				if (aa < bb) {
					aa += s1[i];
					bb += s1[i-1];
				}
				else {
					aa += s1[i-1];
					bb += s1[i];
				}
			}
			if (s1.size() % 2 == 1) {
				if (aa > bb) {
					bb += s1[0];
				}
				else {
					aa += s1[0];
				}
			}
			if (aa > bb) {
				Swap(aa, bb);
			}
			cout << aa << " " << bb << endl;
		}
	}
}
