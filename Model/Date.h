#pragma once
#include<ostream>

class Date
{
	int year;
	int month;
	int day;

	int numDaysInMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31 };
	void nextDate(const int);

public:

	Date(int year = 2022, int mounth = 5, int day = 1);

	void enter();

	void setYear(const int);
	void setMonth(const int);
	void setDay(const int);

	const int getYear() const;
	const int getMonth() const;
	const int getDay() const;

	const Date& operator+=(const int);
	const Date operator+(const int) const;
	const bool operator==(const Date) const;
	bool operator<(const Date date) const;
	const size_t operator-(const Date date) const;
};

std::ostream& operator<<(std::ostream& stream, const Date& interval);

