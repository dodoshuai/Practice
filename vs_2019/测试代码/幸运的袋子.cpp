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
			num +=1+getnum( i + 1, add, mul);//�������Ҫ�󣬾ͼ����ݹ����һ������ʼ
		}
		else if (res[i] == 1) {
			num += getnum(i + 1, add, mul);//�������Ϊ1�������⴦��
		}
		else {
			break;
		}
		add -= res[i];
		mul /= res[i];
		while (i<res.size()-1&&res[i + 1] == res[i] && i + 1 < res.size())//vector��������Խ�磬Ҫ���ж�������������Խ��
		{
			//�ظ������ֶ��ڴ��� ---��̫���Ҫ  ����ɽ���ظ�
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
	sort(res.begin(), res.end());//����
	int num = getnum(0, add, mul);//�ݹ飬��С����ע��1��������
	cout << num << endl;

	return 0;
}