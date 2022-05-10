#pragma once
#include"Date.h"
struct Interval
{
	Date date;
	int periodInDays = 0;

	Interval(Date date, int period) : date(date), periodInDays(period) {}
	Interval() {}

	bool operator==(const Interval& interval) const;
	bool operator<(const Interval& interval) const;

	friend std::ostream& operator<<(std::ostream& stream, const Interval& interval);
};