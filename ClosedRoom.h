#pragma once

#include"Room.h"
#include"Interval.h"

class ClosedRoom : private Room
{
	Interval interval;

public:

	void setId(const size_t&);
	void setInterval(const Interval&);
	bool operator==(const ClosedRoom&) const;

	const size_t& getId() const;
	const Interval& getInterval() const;

	friend std::fstream& operator<<(std::fstream&, const ClosedRoom&);
	friend std::fstream& operator>>(std::fstream&, ClosedRoom&);
	friend std::ostream& operator<<(std::ostream&, const ClosedRoom&);
	friend std::istream& operator>>(std::istream&, ClosedRoom&);
};
