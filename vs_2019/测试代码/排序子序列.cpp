#include<iostream> 
#include<vector>
using namespace std; 
int main() {
	int n;//����

	while (cin >> n) {
		vector<int> nums(n);//����
		for (int i = 0; i < n; ++i) {
			cin >> nums[i];
		}
		int sum = 0;//������
		int flag = 0;//�Ӽ���־λ
		for (int i = 1; i < n; ++i) {
			if (nums[i - 1] > nums[i] && flag ==0) {
				flag = -1;
				sum += 1;
			}
			else if (nums[i - 1] < nums[i] && flag ==0) {
				flag = 1;
				sum += 1; 
			}
			else if (nums[i - 1] > nums[i] && flag == 1) {
				flag = 0;
			}
			else if (nums[i - 1] < nums[i] && flag == -11){
				flag = 0;
			}
		}
		if (flag == 0) {
			sum += 1;
		}
		cout << sum << endl;
	}

	return 0;
}