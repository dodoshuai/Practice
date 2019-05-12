#pragma once
#include<iostream>
using std::cout;
using std::endl;

typedef int TimeType;
class Date {
public:
		int GetMonthDay(TimeType year, TimeType month) {//�����·�����
	static	int array[13]= { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//���ʹ�ã���Ϊ��̬���飬���Խ�ʡʱ��
		if (month == 2) {
			if ((year % 4 == 0 && year % 100 != 0)
						|| (year % 400 == 0)) {
				return 29;
					}
		}
		
		return array[month];
	}
	Date(TimeType year=1990,TimeType month=1,TimeType day=1){//���캯��
		if (year >= 1900
			&& month > 0 && month < 13
			&& day>0 && day < GetMonthDay(year, month)) {
			_year = year;
			_month = month;
			_day = day;
		}
		else
		{
			cout << "�Ƿ�������" << endl;
		}
	}
	~Date(){ //��������
	}
	Date(Date &d) {//��������
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