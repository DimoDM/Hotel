#pragma once
#include<ostream>

class Date
{
	int year;
	int mounth;
	int day;

	int numDaysInMounth[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31 };
	void nextDate(const int);

public:

	Date(int year = 2022, int mounth = 5, int day = 1);

	void init();

	void setYear(const int);
	void setMounth(const int);
	void setDay(const int);

	const int getYear() const;
	const int getMounth() const;
	const int getDay() const;

	const Date& operator+=(const int);
	const Date operator+(const int) const;
	bool operator<(const Date date) const;

};

