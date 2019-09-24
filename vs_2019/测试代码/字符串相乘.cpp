/*
	�����������ַ�����ʽ��ʾ�ķǸ����� num1 �� num2������ num1 �� num2 �ĳ˻������ǵĳ˻�Ҳ��ʾΪ�ַ�����ʽ��
	ʾ�� 1:

����: num1 = "2", num2 = "3"
���: "6"
ʾ�� 2:

����: num1 = "123", num2 = "456"
���: "56088"
˵����

num1 �� num2 �ĳ���С��110��
num1 �� num2 ֻ�������� 0-9��
num1 �� num2 �������㿪ͷ������������ 0 ����
����ʹ���κα�׼��Ĵ������ͣ����� BigInteger����ֱ�ӽ�����ת��Ϊ����������
*/
#include<iostream>
#include<string>
#include<vector>
using namespace std;
string multiply(string num1, string num2) {
	string ss(num1.size() + num2.size(), '0');
//	cout << ss << endl;
	int w = 1;
	for (int i = num1.size() - 1; i >= 0; i--) {//�����һ����ʼ���г˷�����
		int a = num1[i] - '0';
		int sum = 0;
		int c = 0;
		string s = "";
		for (int j = num2.size() - 1; j >= 0; j--) {//��num1��һ��ֵ��num2���
			int b = num2[j] - '0';
			sum = a * b + c;
			int x = sum % 10;
			s = (char)(x + '0') + s;
			c = sum / 10;
			sum = 0;
		}
		if (c != 0) {
			s = (char)(c + '0') + s;
		}

		int m = ss.size() - w;//��λ��ʮλ����λ������������û�е�����Ӧ��С��ֵ���õ�����ֵҪ����Ӧ��λ��
		int c2 = 0;

		for (int q = s.size() - 1; q >= 0; q--) {//��ÿ��λ�ĳ�����ӣ�ȷ����Ľ�λ�������λ�ĳ�����ʮλ�ĳ�����
			int l = ss[m] - '0';
			int k = s[q] - '0';
		//	int y = ss[m] - '0' + s[q] - '0';
			int y = l + k+c2;
			c2 = 0;
			if (y > 9) {
				y = y - 10;
				c2 = 1;
			}
			ss[m--] = (char)(y + '0');
		}
		if (c2 != 0) {
			ss[m]=(char)(c2+'0');
		}
		w++;
	}
//	cout << ss << endl;
	//��ȥ�ַ����׵ġ�0��
	string s3 = "0";
	for (int i = 0; i < ss.size(); i++) {
		if (ss[i] != '0') {
			s3=ss.substr(i, ss.size() - i);
			break;
		}
	}
	return s3;
}
int main() {
	string s1, s2;
	cin >> s1;
	cin >> s2;

	cout << multiply(s1, s2) << endl;
	return 0;
}