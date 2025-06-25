#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
#include <assert.h>

class Date 
{
public:
	Date(int year = 1900, int month = 1, int day = 1);
	void Print();

	int getMonthDay(int year, int month) 
	{
		static int monthDayArray[] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))&&(month == 2)) {
			return 29;
		}
		return monthDayArray[month];
	}

	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);

	Date operator+(int day);
	Date operator-(int day);

	Date& operator+=(int day);
	Date& operator-=(int day);
	int operator-(const Date& d)const;

private:
	int _year;
	int _month;
	int _day;
	
};