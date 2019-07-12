#include<iostream>
#include<vector>
using namespace std;
/*void oddInOddEvenInEven(vector<int>& arr, int len) {
	int j = 0;
	int o = 0;
	for (int i = 0; i < arr.size(); ++i) {
		if (arr[i] % 2 == 1) {
			j++;
		}
		else {
			o++;
		}
	}
	int a = 0;
	int b = 0;
	int flag;
	if (j > o) {
		flag = 1;
		b = 1;
	}
	else {
		flag = 0;
		b = 0;
	}
	while (a < arr.size()&&b<arr.size()) {
		while (arr[a] % 2 != flag ) {
			
			a++;
		}
		if (a % 2 != flag) {
			int temp = arr[a];
			arr[a] = arr[b];
			arr[b] = temp;
			b += 2;
		}
		else {
			a++;
		}

	
	}
}*/
void oddInOddEvenInEven(vector<int>& arr, int len) {
	int a = 0;
	int b = 0;
	int flag = 1;
	for (int i = 0; i < arr.size(); i++)
	{
		flag ^= 1;
		if (i % 2 == flag && arr[i] % 2 != flag) {
			int j;
			for (j = i + 1; j < arr.size(); j++) {
				if (arr[j] % 2 == flag)
					break;
			}
			if (j < arr.size()) {
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}

}

int main() {
	int n;
	cin >> n;
	vector<int> aa(n);
	for (int i = 0; i < n; i++) {
		cin >> aa[i];
	}
	oddInOddEvenInEven(aa, n);
	cout << "-----------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << aa[i] << endl;
	}
	cout << "-------------------" << endl;
	return 0;
}