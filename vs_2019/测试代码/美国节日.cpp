#include<iostream>
#include<vector>
using namespace std;
/*
int WeekToDay(int y, int m, int c, int w, bool B) {//输入哪年哪月第几个星期几，以及正数还是倒数，输出几号
	int d, week, i;
	if (m == 1) { m = 13; y--; }//公式要求1月、2月要转为上一年13、14月
	if (m == 2) { m = 14; y--; }
	i = 0;
	for (d = B ? 1 : 31; d <= B ? 31 : 1; B ? (d++) : (d--)) {//B：正数/倒数
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//蔡勒公式
		if (week + 1 == w) ++i;
		if (i == c) break;
	}
	return d;
}
*/
int WeekToDay(int y, int m, int c, int w, bool B) {
	vector<int> leap = {0, 31,29,31,30,31,30,31,31,30,31,30,31 };
	vector<int> nor = {0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = 5;
	for (int i = 2000; i < y; i++) {
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) {
			day += 366;
		}
		else {
			day += 365;
		}
	}
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) {
		for (int i = 1; i < m; i++) {
			day += leap[i];
		}
	}
	else {
		for (int i = 0; i < m; i++) {
			day += nor[i];
		}
	}
	int a = day % 7;
	int b = 0;
	//cout <<"---------------"<< a <<"----------------"<< endl;
	if (w < (a + 1)) {
		b = (c-1) * 7 + (7 - a)+w;
	}
	else {
		b = (c - 1) * 7 + w - a;
	}
	//day = day + b;
	if (B == 0) {
		while (b + 7 < 31) {
			b += 7;
		}
	//	b += w;
	}
//	cout << "---------------" << b << "----------------" << endl;
	return b;
}

int main(void) {
	int y;
	while (cin >> y) {
		cout << y << "-01-01" << endl;
		printf("%d-01-%02d\n", y, WeekToDay(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, WeekToDay(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, WeekToDay(y, 5, 1, 1, 0));//倒数
		cout << y << "-07-04" << endl;
		printf("%d-09-%02d\n", y, WeekToDay(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, WeekToDay(y, 11, 4, 4, 1));
		cout << y << "-12-25" << endl << endl;
	}
	return 0;
}