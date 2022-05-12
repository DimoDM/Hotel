#include "Interval.h"
#include<iostream>

Interval::Interval(Date date, size_t period)
{
	setDate(date);
	setPeriod(period);
}

void Interval::init()
{
	Date date;
	date.init();
	setDate(date);
	int period;
	std::cout << "enter period of staying: ";
	std::cin >> period;
	setPeriod(period);
}

void Interval::setDate(const Date date)
{
	this->date = date;
}

void Interval::setPeriod(const size_t period)
{
	if (period > 0 && period < 100) this->period = period;
	else {
		std::cout << "If Kamen enter input(mainata ti)\nElse, invalid period. Default of 1 day is set.\n";
		this->period = 1;
	}
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

std::ostream& operator<<(std::ostream& stream, const Interval& interval)
{
	stream << interval.getDate() << " ,period: " << interval.getPeriod();
	return stream;
}