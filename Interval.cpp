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
	setPeriod(period);
}

void Interval::setDate(const Date date)
{
	this->date = date;
}

void Interval::setPeriod(const size_t period)
{
	if (period > 0 && period < 30) this->period = period;
	else {
		std::cout << "If Kamen enter input(mainata ti)\nElse, invalid period. Default of 1 day is set.\n";
		this->period = 1;
	}
}

bool Interval::operator==(const Interval& interval) const
{
	return !((date < interval.date && (date + period) < interval.date)
		|| (interval.date < date && (interval.date + period) < date));
}

bool Interval::operator<(const Interval& interval) const
{
	return date < interval.date;
}

std::ostream& operator<<(std::ostream& stream, const Interval& interval)
{
	stream << interval.date.getYear() << " " << interval.date.getMounth() << " " << interval.date.getDay() << " ,period: " << interval.period;
	return stream;
}