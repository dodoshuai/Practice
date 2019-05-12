#include"date.h"
/*	bool operator>(const Date& d) const;
	bool operator>=(const Date& d) const;
	bool operator<(const Date& d) const;
	bool operator<=(const Date& d) const;
	bool operator==(const Date& d) const;
	bool operator!=(const Date& d) const;
*/
Date& Date:: operator++() {
	*this += 1;
	return *this;
}
Date Date::operator++(int) {
	Date ret=*this;
	*this += 1;
		return ret;
}

//Date operator--();		
//Date operator--(int);	

Date Date:: operator+(int day)const {
	Date ret;
	ret = *this;
	ret._day += day;
	while (ret._day > ret.GetMonthDay(ret._year,ret._month)) {
		ret._day -= ret.GetMonthDay(ret._year,ret._month);
		++ret._month;
		if (ret._month == 13) {
			ret._month = 1;
			++ret._year;
		}
	}
	return ret;
}
//Date operator-(int day) const;

Date& Date:: operator+=(int day) {
	_day += day;
	while (_day > GetMonthDay(_year, _month)) {
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13) {
			_month = 1;
			++_year;
		}
	}
	return *this;
}
//Date& operator-=(int day);

//int operator-(const Date&d);
