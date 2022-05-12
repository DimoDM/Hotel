#include "Interval.h"
#include<iostream>

Interval::Interval(Date date, size_t period)
{
	setDate(date);
	setPeriod(period);
}

void Interval::setDate(const Date date)
{
	this->date = date;
}

void Interval::setPeriod(size_t period)
{
	if (period == 0 || period >= 100) {
		std::cout << "Invalid period. Default of 1 day is set.\n";
		period = 1;
	}
	this->period = period;
}

const Date Interval::getDate() const
{
	return date;
}

const int Interval::getPeriod() const
{
	return period;
}

bool Interval::operator==(const Interval& interval) const
{
	return (date < interval.date && interval.date < (date + period)) || (interval.date < date&& date < (interval.date + interval.period)) || interval.date == date;

	if (date < interval.date) {
		if ((date + period) < interval.date) return false;
		return true;
	}
	else if (interval.date < date) {
		if ((interval.date + interval.period) < date) return false;
		return true;
	}
	return true;
}

bool Interval::operator<(const Interval& interval) const
{
	return (date + period) < interval.date;
}

std::istream& operator>>(std::istream& stream, Interval& interval)
{
	Date date;
	stream >> date;
	interval.setDate(date);
	int period;
	std::cout << "enter period: ";
	stream >> period;
	interval.setPeriod(period);
	return stream;
}

std::ostream& operator<<(std::ostream& stream, const Interval& interval)
{
	stream << interval.getDate() << " ,period: " << interval.getPeriod();
	return stream;
}