#include<iostream>

using namespace std;
int getday(int year, int month, int day)
{
	if (month > 12 || month < 0)
		return -1;
	int ret = 0;
	int nums[] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		nums[2] = 29;
	if (day < 0 || nums[month] < day) {
		return -1;
	}
		for (int i = 0; i < month; ++i) {
		ret += nums[i];
	}
	ret += day;
	return ret;
}

int main() {
	int year, month, day;
	cin >> year >> month >> day;
	cout << getday(year,month,day) << endl;
	return 0;
}