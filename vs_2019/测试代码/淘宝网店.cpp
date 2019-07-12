#include<iostream>
using namespace std;

int main() {
	int year1, month1, day1;
	int d[12] = {  31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int year2, month2, day2;
	while(cin >> year1 >> month1 >> day1 >> year2 >> month2 >>day2){
	int num = 0;
	for (int i = year1; i <= year2 - 1; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			num += 580;
		}
		else {
			num += 579;
		}
	}
	for (int i = 0; i <= month1 - 1; ++i) {
		int temp = 0;
		if (i == month1 - 1) temp = day1 - 1;
		else temp = d[i];
		if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) { num -= temp * 2; }
		else num -= temp;
	}
	for (int i = 0; i <= month2 - 1; ++i) {
		int temp = 0;
		if (i == month2 - 1) temp = day2;
		else temp = d[i];
		if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) { num += temp * 2; }
		else num += temp;
	}
	cout << num << endl;
}
	return 0;
}