#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 
vector<int> res;
int getnum(int pos, int add, long long mul) {
	int num=0;
	for (int i = pos; i <res.size(); ++i) {
		add += res[i];
		mul *= res[i];
		if (add > mul) {
			num +=1+getnum( i + 1, add, mul);//如果符合要求，就继续递归从下一个数开始
		}
		else if (res[i] == 1) {
			num += getnum(i + 1, add, mul);//如果数字为1，做特殊处理
		}
		else {
			break;
		}
		add -= res[i];
		mul /= res[i];
		while (i<res.size()-1&&res[i + 1] == res[i] && i + 1 < res.size())//vector会检测数组越界，要有判断条件避免数组越界
		{
			//重复的数字对于此题 ---无太大必要  会造成结果重复
			++i;
		}

	}
	return num;
}

int main() {
	int n;
	cin >> n;
	int add = 0;
	long long mul = 1;
	
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		res.push_back(a);
	}
	sort(res.begin(), res.end());//排序
	int num = getnum(0, add, mul);//递归，从小到大，注意1的特殊性
	cout << num << endl;

	return 0;
}