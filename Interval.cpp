#include "Interval.h"

void Interval::setDate(const Date)
{

}

bool Interval::operator==(const Interval& interval) const
{
	return !((date < interval.date && (date + periodInDays) < interval.date)
		|| (interval.date < date && (interval.date + periodInDays) < date));
}

bool Interval::operator<(const Interval& interval) const
{
	return date < interval.date;
}

std::ostream& operator<<(std::ostream& stream, const Interval& interval)
{
	stream << interval.date.getYear() << " " << interval.date.getMounth() << " " << interval.date.getDay() << " ,period: " << interval.periodInDays;
	return stream;
}