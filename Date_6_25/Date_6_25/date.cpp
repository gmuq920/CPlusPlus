#define _CRT_SECURE_NO_WARNINGS
#include"date.h"

Date::Date(int year , int month , int day )
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::Print() 
{
	cout << _year << '.' << _month << "." << _day << endl;
}

bool Date::operator<(const Date& d) 
{
	if (_year < d._year) {
		return true;
	}
	else if (_year > d._year) {
		return false;
	}
	else {
		if (_month > d._month) {
			return false;
		}
		else if (_month < d._month) {
			return true;
		}
		else {
			if (_day < d._day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator<=(const Date& d)
{
	if (_year < d._year) {
		return true;
	}
	else if (_year > d._year) {
		return false;
	}
	else {
		if (_month > d._month) {
			return false;
		}
		else if (_month < d._month) {
			return true;
		}
		else {
			if (_day <= d._day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator>(const Date& d) 
{
	if (_year > d._year) {
		return true;
	}
	else if (_year < d._year) {
		return false;
	}
	else {
		if (_month < d._month) {
			return false;
		}
		else if (_month > d._month) {
			return true;
		}
		else {
			if (_day > d._day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator>=(const Date& d)
{
	if (_year > d._year) {
		return true;
	}
	else if (_year < d._year) {
		return false;
	}
	else {
		if (_month < d._month) {
			return false;
		}
		else if (_month > d._month) {
			return true;
		}
		else {
			if (_day >= d._day) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d) 
{
	return _year != d._year || _month != d._month || _day != d._day;
}

Date Date::operator+(int day) 
{
	Date tmp = *this;
	tmp._day += day;
	while (tmp._day > getMonthDay(tmp._year, tmp._month))
	{
		tmp._day -= getMonthDay(tmp._year, tmp._month);
		tmp._month++;
		if (tmp._month == 13) {
			tmp._year++;
			tmp._month = 1;
		}
	}
	return tmp;
}

Date Date::operator-(int day) 
{
	Date tmp = *this;
	tmp._day -= day;
	while (tmp._day <= 0) 
	{
		tmp._month--;

		if (tmp._month == 0)
		{
			tmp._year--;
			tmp._month = 12;
		}

		tmp._day += getMonthDay(tmp._year, tmp._month);
	}
	return tmp;
}

Date& Date::operator+=(int day) 
{
	_day += day;
	while (_day > getMonthDay(_year, _month)) 
	{
		_day -= getMonthDay(_year, _month);
		_month++;

		if (_month == 13) 
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date& Date::operator-=(int day) 
{
	_day -= day;
	while (_day <= 0) 
	{
		_month--;
		if (_month == 0) 
		{
			_year--;
			_month = 12;
		}
		_day += getMonthDay(_year, _month);
	}
	return *this;
}

int Date::operator-(const Date& d)const
{
	Date tmp = *this;
	int count = 0;
	while (tmp > d) {
		count++;
		tmp -= 1;
	}

	while (tmp < d) 
	{
		count--;
		tmp += 1;
	}
	return count;
}

