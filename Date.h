#pragma once
#include<ostream>

class Date
{
	int year = 2022;
	int mounth = 5;
	int day = 1;

	const Date& operator+=(const int period) {
		nextDate(period);
		return *this;
	}
	const Date operator+(const int period) const {
		Date date = *this;
		date += period;
		return date;
	}
	bool operator<(const Date date) const {
		return year <= date.year && mounth <= date.mounth && day < date.day;
	}

private:
	int numDaysInMounth[12] = { 31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31 };
	void nextDate(const int period) {
		if (year % 4 == 0) numDaysInMounth[1] = 29;
		else numDaysInMounth[1] = 28;
		if (day + period > numDaysInMounth[mounth]) {
			int residue = period - (numDaysInMounth[mounth] - day);
			if (++mounth > 12) {
				mounth = 1;
				year++;
			}
			nextDate(residue);
		}
		else day += period;
	}
};

