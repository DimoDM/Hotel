#include "Interval.h"

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
	stream << interval.date.year << " " << interval.date.mounth << " " << interval.date.day << " ,period: " << interval.periodInDays;
	return stream;
}