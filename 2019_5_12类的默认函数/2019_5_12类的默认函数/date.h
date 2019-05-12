#pragma once
#include<iostream>
using std::cout;
using std::endl;

typedef int TimeType;
class Date {
public:
		int GetMonthDay(TimeType year, TimeType month) {//返回月份天数
	static	int array[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//多次使用，设为静态数组，可以节省时间
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0)
						|| (year % 400 == 0)) {
				return 29;
					}
		}
		
		return array[month];
	}
	Date(TimeType year=1990,TimeType month=1,TimeType day=1){//构造函数
		if (year >= 1900
			&& month > 0 && month < 13
			&& day>0 && day < GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "非法操作！" << endl;
		}
	}
	~Date(){ //析构函数
	}
	Date(Date &d) {//拷贝构造
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;

	Date& operator++();		// 
	Date operator++(int);	// 

	Date operator--();		// 
	Date operator--(int);	// 

	Date operator+(int day) const;
	Date operator-(int day) const;

	Date& operator+=(int day);
	Date& operator-=(int day);

	int operator-(const Date&d);
private:

	TimeType _year;
	TimeType _month;
	TimeType _day;
};