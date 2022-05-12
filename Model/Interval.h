#pragma once
#include"Date.h"
class Interval
{
	Date date;
	size_t period = 0;

public:

	Interval(Date date, size_t period);
	Interval() = default;

	void enter();
	void setDate(const Date);
	void setPeriod(const size_t);

	const Date getDate() const;
	const int getPeriod() const;

	bool operator==(const Interval& interval) const;
	bool operator<(const Interval& interval) const;

};

std::ostream& operator<<(std::ostream& stream, const Interval& interval);