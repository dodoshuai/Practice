#include<iostream>
#include<vector>
using namespace std;
int superEggDrop(int K, int N) {
	vector<int>record(K + 1, 1);//����0�������������������Ҫ����K+1���ռ䡣ֻ����һ�ε�ʱ�����۶��ٸ���������߶�ֻ�ܲ�1��
	record[0] = 0;//0��������������⻯����Ϊ0
	int move = 2;//�������2��
	while (record[K] < N)//��record[K]���ڵ���N��ʱ����˳�ѭ��
	{
		for (int i = K; i >= 1; i--)//��vector�ĺ��濪ʼ���£�������Ӱ������λ�õ�vectorԪ�صĸ���
			record[i] = record[i] + record[i - 1] + 1;
		cout << "----------------------" << endl;
		for (int i = 0; i < record.size(); i++) {
			cout <<i<< "="  <<record[i] << " ";
		}
		cout << endl;
		cout << "----------------------" << endl;
		move++;//move+1���ٳ���һ��
		cout << move << endl;
	}

	return move - 1;//������Ҫ�ĳ��Դ���
}

int main() {
	int k;
	int n;
	while(cin >> k >> n)
	cout << superEggDrop(k, n) << endl;
	return 0;

}