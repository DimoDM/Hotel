#pragma once
#include"Date.h"
class Interval
{
	Date date;
	size_t period = 0;

public:

	Interval(Date date, size_t period);
	Interval() {}

	void setDate(const Date);
	void setPeriod(const size_t);

	bool operator==(const Interval& interval) const;
	bool operator<(const Interval& interval) const;

	friend std::ostream& operator<<(std::ostream& stream, const Interval& interval);
};